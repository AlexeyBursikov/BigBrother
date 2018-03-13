#include "BaseScreen.h"

using namespace bbrother;

BaseScreen::BaseScreen()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "BaseScreen init");
	font.load("ofxbraitsch/fonts/Verdana.ttf", 64);
}

void BaseScreen::update()
{
	
}

void BaseScreen::draw()
{
	string msg = "BaseScreen";
	font.drawString(msg, ofGetWidth() / 2 - msg.size() * 36 / 2, ofGetHeight() / 2);
}

BaseScreen::~BaseScreen()
{

}
