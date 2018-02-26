#include "TestKinectInterfaceLayout.h"

using namespace bbrother;

TestKinectInterfaceLayout::TestKinectInterfaceLayout()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "IFish InterfaceLayout init");

	kinectStartButton = ofPtr<ofxDatGuiButton>(new ofxDatGuiButton("Kinect Start"));
	kinectStartButton->onButtonEvent(this, &TestKinectInterfaceLayout::kinectStartButtonClicked);
	kinectStartButton->setPosition(20, 20);
}

void TestKinectInterfaceLayout::update()
{
	kinectStartButton->update();
}

void TestKinectInterfaceLayout::draw()
{
	kinectStartButton->draw();
}

void TestKinectInterfaceLayout::kinectStartButtonClicked(ofxDatGuiButtonEvent event)
{
	auto type = InterfaceEventType::TrackingStart;
	ofNotifyEvent(InterfaceEvent, type);
}

TestKinectInterfaceLayout::~TestKinectInterfaceLayout()
{

}
