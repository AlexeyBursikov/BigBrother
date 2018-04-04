#include "FamilyBaseRequestHandler.h"
#include "json/JsonFamilyParser.h"

using namespace bbrother;

FamilyBaseRequestHandler::FamilyBaseRequestHandler()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Family Base Request Handler init");
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

vector<FamilyBaseRequestHandler::HeaderParam> FamilyBaseRequestHandler::getOathHeaders() const
{
	vector<HeaderParam> headerParams;
	headerParams.push_back(HeaderParam("Content-Type", "application/json"));
	headerParams.push_back(HeaderParam("Authorization", "Bearer " + requestAccessData.accessToken));
	return headerParams;
}

void FamilyBaseRequestHandler::oathRequest()
{
	requestType = FamilyRequest::Oath;	
	vector<RequestParam> requestParams;
	requestParams.push_back(RequestParam("grant_type", oathRequestData.grantType));
	requestParams.push_back(RequestParam("client_id", to_string(oathRequestData.clientId)));
	requestParams.push_back(RequestParam("client_secret", oathRequestData.clientSecret));
	requestParams.push_back(RequestParam("username", oathRequestData.username));
	requestParams.push_back(RequestParam("password", oathRequestData.password));

	vector<HeaderParam> headerParams;

	makeRequest(getRequestUrl(requestType), HTTPRequestMethod::POST, requestParams, headerParams);
}

void FamilyBaseRequestHandler::getUsersRequest()
{
	requestType = FamilyRequest::GetUsers;		
	vector<RequestParam> requestParams;
	makeRequest(getRequestUrl(requestType), HTTPRequestMethod::GET, requestParams, getOathHeaders());
}

void FamilyBaseRequestHandler::createUserRequest(const string& name, const string& masterToken)
{
	requestType = FamilyRequest::CreateUser;	
	vector<RequestParam> requestParams;
	requestParams.push_back(RequestParam("name", name));
	requestParams.push_back(RequestParam("master_token", masterToken));

	makeRequest(getRequestUrl(requestType), HTTPRequestMethod::POST, requestParams, getOathHeaders());
}

void FamilyBaseRequestHandler::makeRequest(const string& Url, HTTPRequestMethod requestMethod, const vector<RequestParam>& requestParams, const vector<HeaderParam>& headerParams)
{
	ofAddListener(httpUtils.newResponseEvent, this, &FamilyBaseRequestHandler::onServerResponse);	
	httpUtils.start();

	ofxHttpForm form;
	form.action = Url;	
	form.method = (int)requestMethod;	

	for (auto param : requestParams)
	{
		form.addFormField(param.key, param.value);
	}

	for (auto param : headerParams)
	{
		form.addHeaderField(param.key, param.value);
	}

	httpUtils.addForm(form);
}

void FamilyBaseRequestHandler::onServerResponse(ofxHttpResponse& response)
{
	JsonFamilyParser parser(response.responseBody);
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
		cout << "get users response " << response.responseBody << endl;
		break;
	case FamilyRequest::CreateUser:
		cout << "create user response " << response.responseBody << endl;
		break;
	}	
}

FamilyBaseRequestHandler::~FamilyBaseRequestHandler()
{

}
