#include "DetectScreen.h"

using namespace bbrother;

DetectScreen::DetectScreen()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Detect Screen init");
}

void DetectScreen::update()
{

}

void DetectScreen::draw()
{
	string msg = "DetectScreen";
	font.drawString(msg, ofGetWidth() / 2 - msg.size() * 36 / 2, ofGetHeight() / 2);
}

DetectScreen::~DetectScreen()
{

}