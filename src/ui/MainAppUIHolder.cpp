#include "MainAppUIHolder.h"
#include "screens/WaitScreen.h"

using namespace bbrother;

MainAppUIHolder::MainAppUIHolder()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "MainAppUIHolder init");
	currentScreen = bbrother::BaseScreenPtr(new WaitScreen());
}

void MainAppUIHolder::newPersonAppear(PersonPtr person)
{
	
}

void MainAppUIHolder::update()
{
	currentScreen->update();
}

void MainAppUIHolder::draw()
{
	currentScreen->draw();
}

MainAppUIHolder::~MainAppUIHolder()
{

}
