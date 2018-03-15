#include "WaitScreen.h"

using namespace bbrother;

WaitScreen::WaitScreen()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Wait Screen init");
}

void WaitScreen::update()
{
	
}

void WaitScreen::draw()
{
	std::string msg = "WaitScreen";
	font.drawString(msg, ofGetWidth() / 2 - msg.size() * 36 / 2, ofGetHeight() / 2);
}

WaitScreen::~WaitScreen()
{

}
