#include "ResultScreen.h"

using namespace bbrother;

ResultScreen::ResultScreen()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, " Result Screen init");
}

void  ResultScreen::update()
{

}

void  ResultScreen::draw()
{
	string msg = "ResultScreen";
	font.drawString(msg, ofGetWidth() / 2 - msg.size() * 36 / 2, ofGetHeight() / 2);
}

ResultScreen::~ResultScreen()
{

}