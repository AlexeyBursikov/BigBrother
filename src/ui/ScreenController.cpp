#include "ScreenController.h"
#include "screens/WaitScreen.h"

using namespace bbrother;

ScreenController::ScreenController()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "MainAppUIHolder init");
	currentScreen = bbrother::BaseScreenPtr(new WaitScreen());
}

void ScreenController::newPersonAppear(PersonPtr person)
{
	
}

void ScreenController::update()
{
	currentScreen->update();
}

void ScreenController::draw()
{
	currentScreen->draw();
}

ScreenController::~ScreenController()
{

}
