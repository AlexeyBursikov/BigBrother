#include "ofApp.h"
#include "config/Config.h"
#include "interface/TestKinectInterfaceLayout.h"
#include "tracker/KinectTracker.h"
#include "facedetector/FacePlusPlusDetector.h"

using namespace bbrother;

//--------------------------------------------------------------
void ofApp::setup()
{
	config = ConfigPtr(new Config());
	ofAddListener(config->loadCompleteEvent, this, &ofApp::onConfigLoadComplete);

#ifdef DEBUG_VERSION	
	testInterfaceLayout = TestInterfaceLayoutPtr(new TestKinectInterfaceLayout());
	testInterfaceLayout->setPosition(ofPoint(20, 40));
	testInterfaceLayout->setVisibility(true);
	ofAddListener(testInterfaceLayout->InterfaceEvent, this, &ofApp::onInterfaceEvent);
#endif

	tracker = bbrother::TrackerPtr(new KinectTracker());
	facedetector = bbrother::FaceDetectorPtr(new FacePlusPlusDetector());
	mainUI = bbrother::MainAppUIHolderPtr(new MainAppUIHolder());

	//printerWorker = bbrother::PrinterWorkerPtr(new PrinterWorker());	
	//tcpController = TcpControllerPtr(new TcpController());

	config->load();
}

//--------------------------------------------------------------
void ofApp::onConfigLoadComplete()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Config load complete");

	ofLog(ofLogLevel::OF_LOG_NOTICE, "Start application...");
}

//--------------------------------------------------------------
void ofApp::onInterfaceEvent(bbrother::InterfaceEventType& Event)
{
	switch (Event)
	{
	case InterfaceEventType::TrackingStart:
		ofLog(ofLogLevel::OF_LOG_NOTICE, "Try kinect starts...");
		break;
	}
}

//--------------------------------------------------------------
void ofApp::update()
{
	tracker->update();
	mainUI->update();

#ifdef DEBUG_VERSION
	testInterfaceLayout->update();
#endif
}

//--------------------------------------------------------------
void ofApp::draw()
{
	tracker->draw();
	mainUI->draw();

#ifdef DEBUG_VERSION
	// on top level
	testInterfaceLayout->draw();
#endif
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

