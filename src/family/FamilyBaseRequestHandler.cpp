#include "FamilyBaseRequestHandler.h"
#include "json/JsonFamilyParser.h"

using namespace bbrother;

FamilyBaseRequestHandler::FamilyBaseRequestHandler()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Family Base Request Handler init");
	ofAddListener(httpService.ServerResponseEvent, this, &FamilyBaseRequestHandler::onServerResponse);
}

string FamilyBaseRequestHandler::getRequestUrl(FamilyRequest request) const
{
	const string delimeter = "/";
	switch (request)
	{
	case FamilyRequest::Oath:
		return baseUrl + delimeter + "oauth/token";
	case FamilyRequest::GetUsers:
		return baseUrl + delimeter + "api/users";
	case FamilyRequest::CreateUser:
		return baseUrl + delimeter + "api/users";		
	}
}

void FamilyBaseRequestHandler::init(ConfigPtr config)
{	
	string protocol = "http";
	string host = "bbrother.familyagency.ru";
	baseUrl = protocol + "://" + host;

	oathRequestData.grantType = "password";
	oathRequestData.clientId = 4;
	oathRequestData.clientSecret = "";
	oathRequestData.username = "";
	oathRequestData.password = "";
}

vector<HttpService::HeaderParam> FamilyBaseRequestHandler::getOathHeaders() const
{
	vector<HttpService::HeaderParam> headerParams;
	headerParams.push_back(HttpService::HeaderParam("Content-Type", "application/json"));
	headerParams.push_back(HttpService::HeaderParam("Authorization", "Bearer " + requestAccessData.accessToken));
	return headerParams;
}

void FamilyBaseRequestHandler::oathRequest()
{
	requestType = FamilyRequest::Oath;	
	vector<HttpService::RequestParam> requestParams;
	requestParams.push_back(HttpService::RequestParam("grant_type", oathRequestData.grantType));
	requestParams.push_back(HttpService::RequestParam("client_id", to_string(oathRequestData.clientId)));
	requestParams.push_back(HttpService::RequestParam("client_secret", oathRequestData.clientSecret));
	requestParams.push_back(HttpService::RequestParam("username", oathRequestData.username));
	requestParams.push_back(HttpService::RequestParam("password", oathRequestData.password));

	vector<HttpService::HeaderParam> headerParams;

	httpService.makeRequest(getRequestUrl(requestType), HTTPRequestMethod::POST, requestParams, headerParams);
}

void FamilyBaseRequestHandler::getUsersRequest()
{
	requestType = FamilyRequest::GetUsers;		
	vector<HttpService::RequestParam> requestParams;
	httpService.makeRequest(getRequestUrl(requestType), HTTPRequestMethod::GET, requestParams, getOathHeaders());
}

void FamilyBaseRequestHandler::createUserRequest(const string& name, const string& masterToken)
{
	requestType = FamilyRequest::CreateUser;	
	vector<HttpService::RequestParam> requestParams;
	requestParams.push_back(HttpService::RequestParam("name", name));
	requestParams.push_back(HttpService::RequestParam("master_token", masterToken));

	httpService.makeRequest(getRequestUrl(requestType), HTTPRequestMethod::POST, requestParams, getOathHeaders());
}

void FamilyBaseRequestHandler::onServerResponse(const string& response)
{
	JsonFamilyParser parser(response);
	bool success = false;

	switch (requestType)
	{
	case FamilyRequest::Oath:
		success = parser.parseOath(requestAccessData);
		if (success)
		{
			cout << "token " << requestAccessData.accessToken << endl;			
			getUsersRequest();
			//createUserRequest("kittie", "sggsgsdfbgbfa33414bbg");
		}
		break;
	case FamilyRequest::GetUsers:
		cout << "get users response " << response<< endl;
		break;
	case FamilyRequest::CreateUser:
		cout << "create user response " << response << endl;
		break;
	}	
}

void FamilyBaseRequestHandler::update()
{
	httpService.update();
}

FamilyBaseRequestHandler::~FamilyBaseRequestHandler()
{

}
