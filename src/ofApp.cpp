#include "ofApp.h"
#include "config/Config.h"
#include "interface/BigBrotherInterfaceLayout.h"
#include "tracker/KinectTracker.h"

using namespace bbrother;

//--------------------------------------------------------------
void ofApp::setup()
{
	config = ConfigPtr(new Config());
	ofAddListener(config->loadCompleteEvent, this, &ofApp::onConfigLoadComplete);

#ifdef DEBUG_VERSION	
	interfaceLayout = InterfaceLayoutPtr(new BigBrotherInterfaceLayout());
	ofAddListener(interfaceLayout->InterfaceEvent, this, &ofApp::onInterfaceEvent);
#endif

	tracker = bbrother::TrackerPtr(new KinectTracker());

	//facedetector = bbrother::FaceDetectorPtr(new FacePlusPlusDetector());

	artDrawer = bbrother::ArtDrawerPtr(new ArtDrawer());

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
	artDrawer->update();

	/*schedule->update();
	soundManager->update();*/

#ifdef DEBUG_VERSION
	interfaceLayout->update();
#endif
}

//--------------------------------------------------------------
void ofApp::draw()
{
	tracker->draw();
	artDrawer->draw();

#ifdef DEBUG_VERSION
	// on top level
	interfaceLayout->draw();
#endif
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

