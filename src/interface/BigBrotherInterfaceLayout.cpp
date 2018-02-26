#include "BigBrotherInterfaceLayout.h"

using namespace bbrother;

BigBrotherInterfaceLayout::BigBrotherInterfaceLayout()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "IFish InterfaceLayout init");

	kinectStartButton = ofPtr<ofxDatGuiButton>(new ofxDatGuiButton("Kinect Start"));
	kinectStartButton->onButtonEvent(this, &BigBrotherInterfaceLayout::kinectStartButtonClicked);
	kinectStartButton->setPosition(20, 20);
}

void BigBrotherInterfaceLayout::update()
{
	kinectStartButton->update();
}

void BigBrotherInterfaceLayout::draw()
{
	kinectStartButton->draw();
}

void BigBrotherInterfaceLayout::kinectStartButtonClicked(ofxDatGuiButtonEvent event)
{
	auto type = InterfaceEventType::TrackingStart;
	ofNotifyEvent(InterfaceEvent, type);
}

BigBrotherInterfaceLayout::~BigBrotherInterfaceLayout()
{

}
