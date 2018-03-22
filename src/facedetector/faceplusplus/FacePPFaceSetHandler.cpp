#include "FacePPFaceSetHandler.h"
#include "ofxJSON.h"
#include "json/JsonParser.h"

using namespace bbrother;

FacePPFaceSetHandler::FacePPFaceSetHandler()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Face Plus Plus Detector init");	
}

void FacePPFaceSetHandler::init(ConfigPtr config)
{
	string FACE_PROTOCOL = "https";
	string FACE_HOST = "api-us.faceplusplus.com";
	string FACE_METHOD = "facepp/v3/detect";
	
	FACE_URL = FACE_PROTOCOL + "://" + FACE_HOST + "/" + FACE_METHOD;
	API_KEY = "t1y6VUUSmxx8yLUiww5SwiigbR-CWPrr";
	API_SECRET = "A4dY2MQMKXEJgomNBWNkBANwKGB9ssEe";

}

void FacePPFaceSetHandler::makeRequest(const string& FACE_URL, const string& API_KEY, const string& API_SECRET, const string& filePath)
{
	
}

FacePPFaceSetHandler::~FacePPFaceSetHandler()
{

}
