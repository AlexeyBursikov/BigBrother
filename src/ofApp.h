#pragma once

#include "ofMain.h"
#include "tracker/Tracker.h"
#include "config/Config.h"
#include "art/ArtDrawer.h"
#include "interface/InterfaceLayout.h"

#define DEBUG_VERSION//

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
	
		void windowResized(int w, int h);

private:
	bbrother::ConfigPtr config;
	bbrother::TrackerPtr tracker;
	bbrother::ArtDrawerPtr artDrawer;

#ifdef DEBUG_VERSION
	bbrother::InterfaceLayoutPtr interfaceLayout;
#endif

	void onConfigLoadComplete();
	void onInterfaceEvent(bbrother::InterfaceEventType& Event);
};
