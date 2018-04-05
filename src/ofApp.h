#pragma once
#include "ofMain.h"
#include "tracker/Tracker.h"
#include "config/Config.h"
#include "ui/MainAppUIHolder.h"
#include "interface/TestInterfaceLayout.h"
#include "facedetector/controller/FaceController.h"
#include "family/FamilyBaseRequestHandler.h"

#define DEBUG_VERSION//

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void windowResized( int w, int h );

private:
	bbrother::ConfigPtr config;
	bbrother::TrackerPtr tracker;
	bbrother::FaceDetectorPtr facedetector;
	bbrother::MainAppUIHolderPtr mainUI;	
	bbrother::FaceControllerPtr faceController;


#ifdef DEBUG_VERSION
	bbrother::TestInterfaceLayoutPtr testKinectInterfaceLayout;
	bbrother::TestInterfaceLayoutPtr testMainUIInterfaceLayout;
#endif

	void onConfigLoadComplete();
	void onInterfaceEvent( bbrother::InterfaceEventType& Event );
};