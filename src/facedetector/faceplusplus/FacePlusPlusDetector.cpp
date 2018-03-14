#include "FacePlusPlusDetector.h"
#include "ofxJSON.h"

using namespace bbrother;

FacePlusPlusDetector::FacePlusPlusDetector()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Face Plus Plus Detector init");	
}

void FacePlusPlusDetector::init( ConfigPtr config )
{
	string FACE_PROTOCOL = "https";
	string FACE_HOST = "api-us.faceplusplus.com";
	string FACE_METHOD = "facepp/v3/detect";
	
	FACE_URL = FACE_PROTOCOL + "://" + FACE_HOST + "/" + FACE_METHOD;
	API_KEY = "t1y6VUUSmxx8yLUiww5SwiigbR-CWPrr";
	API_SECRET = "A4dY2MQMKXEJgomNBWNkBANwKGB9ssEe";

	//const string filePath = "c:\\projects\\Openframeworks\\of_v0.9.8_vs_release\\apps\\myApps\\BigBrother\\bin\\data\\face.jpg";
	const string filePath = "c:\\face1.jpg";
	makeRequest(FACE_URL, API_KEY, API_SECRET, filePath);
}

void FacePlusPlusDetector::makeRequest(const string& FACE_URL, const string& API_KEY, const string& API_SECRET, const string& filePath)
{
	ofAddListener(httpUtils.newResponseEvent, this, &FacePlusPlusDetector::newResponse);
	httpUtils.start();

	ofxHttpForm form;
	form.action = FACE_URL;
	cout << "FACE_URL: " << FACE_URL << endl;
	form.method = OFX_HTTP_POST;
	form.addFormField("api_key", API_KEY);
	form.addFormField("api_secret", API_SECRET);
	form.addFile("image_file", filePath);
	form.addFormField( "return_attributes", "gender,age,ethnicity,beauty" );
	httpUtils.addForm(form);
}
//--------------------------------------------------------------
void FacePlusPlusDetector::newResponse(ofxHttpResponse & response) 
{
	auto responseStr = ofToString(response.status) + ": " + (string)response.responseBody;
	cout << "responseStr: " << responseStr << endl;
	ofxJSONElement json(response.responseBody);
	string res = json.getRawString( true );
	std::cout << std::endl << res;
}

FacePlusPlusDetector::~FacePlusPlusDetector()
{

}
