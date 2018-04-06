#include "FacePlusPlusDetector.h"
#include "ofxJSON.h"
#include "json/JsonParserFaceplusPlus.h"

using namespace bbrother;

FacePlusPlusDetector::FacePlusPlusDetector()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Face Plus Plus Detector init");
	ofAddListener(httpService.ServerResponseEvent, this, &FacePlusPlusDetector::onServerResponse);
}

void FacePlusPlusDetector::init(ConfigPtr config)
{
	string FACE_PROTOCOL = "https";
	string FACE_HOST = "api-us.faceplusplus.com";
	string FACE_METHOD = "facepp/v3/detect";
	
	FACE_URL = FACE_PROTOCOL + "://" + FACE_HOST + "/" + FACE_METHOD;
	API_KEY = "t1y6VUUSmxx8yLUiww5SwiigbR-CWPrr";
	API_SECRET = "A4dY2MQMKXEJgomNBWNkBANwKGB9ssEe";

	setPhotoProcessStatus(PhotoProcessStatus::WaitForPhoto);
}

void FacePlusPlusDetector::processImage(const string& path) 
{
	setPhotoProcessStatus(PhotoProcessStatus::Process);

	vector<HttpService::RequestParam> requestParams;
	requestParams.push_back(HttpService::RequestParam("api_key", API_KEY));
	requestParams.push_back(HttpService::RequestParam("api_secret", API_SECRET));
	requestParams.push_back(HttpService::RequestParam("return_attributes", "gender,age,ethnicity,beauty"));

	HttpService::RequestParam fileParam("image_file", path);

	vector<HttpService::HeaderParam> headerParams;
	httpService.makeRequest(FACE_URL, HTTPRequestMethod::POST, requestParams, fileParam);
}

void FacePlusPlusDetector::update()
{
	httpService.update();
}

void FacePlusPlusDetector::onServerResponse(const string& response)
{
	JsonParserFaceplusPlus parser(response);
	bool success = parser.parse();

	if (success)
	{
		FacePtr face = parser.getFace();
		setPhotoProcessStatus(PhotoProcessStatus::Detect);
		face->print();
	}
	else
	{
		setPhotoProcessStatus(PhotoProcessStatus::NotDetect);
	}
}

FacePlusPlusDetector::~FacePlusPlusDetector()
{

}