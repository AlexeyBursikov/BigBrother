#include "FacePlusPlusDetector.h"


using namespace bbrother;

FacePlusPlusDetector::FacePlusPlusDetector()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Face Plus Plus Detector init");	
	makeRequest();
}

void FacePlusPlusDetector::makeRequest()
{
	string const FACE_PROTOCOL = "https";
	string const FACE_HOST = "api-us.faceplusplus.com";
	string const FACE_METHOD = "/facepp/v3/detect";
	string const FACE_URL = FACE_PROTOCOL + "://"+ FACE_HOST + FACE_METHOD;
	string const API_KEY = "MA2zIsaERn-g6x3ngsfAjTGZLPylVh8b";
	string const API_SECRET = "s9Gn2v8GOe6w5WMCh8ywYMJIcVRUlxlh";

	ofAddListener(httpUtils.newResponseEvent, this, &FacePlusPlusDetector::newResponse);
	httpUtils.start();

	ofxHttpForm form;
	form.action = FACE_URL;
	cout << "FACE_URL: " << FACE_URL << endl;
	form.method = OFX_HTTP_POST;
	form.addFormField("api_key", API_KEY);
	form.addFormField("api_secret", API_SECRET);
	form.addFile("image_file", "c:\\projects\\Openframeworks\\of_v0.9.8_vs_release\\apps\\myApps\\BigBrother\\bin\\data\\face.jpg");
	httpUtils.addForm(form);
}
//--------------------------------------------------------------
void FacePlusPlusDetector::newResponse(ofxHttpResponse & response) 
{
	auto responseStr = ofToString(response.status) + ": " + (string)response.responseBody;
	cout << "responseStr: " << responseStr << endl;
}


FacePlusPlusDetector::~FacePlusPlusDetector()
{

}
