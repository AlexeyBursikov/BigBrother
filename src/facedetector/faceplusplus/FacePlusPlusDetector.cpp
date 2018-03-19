#include "FacePlusPlusDetector.h"
#include "ofxJSON.h"
#include "JsonParser.h"

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

	test = WaitForPhoto;
	ofNotifyEvent( status_event, test );
}

void FacePlusPlusDetector::ProcessImage(string path_) {
	path = path_;
	makeRequest( FACE_URL, API_KEY, API_SECRET, path );
}

void FacePlusPlusDetector::makeRequest(const string& FACE_URL, const string& API_KEY, const string& API_SECRET, const string& filePath)
{
	test = Process;
	ofNotifyEvent( status_event, test );

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


void FacePlusPlusDetector::newResponse( ofxHttpResponse & response )
{
	JsonParser parser( response.responseBody );
	Face* res = parser.Parse();

	if( res == NULL ) {
		test = NotDetect;
		ofNotifyEvent( status_event, test );
	} else {
		test = Detect;
		ofNotifyEvent( status_event, test );
		res->Print();
	}
}

FacePlusPlusDetector::~FacePlusPlusDetector()
{

}
