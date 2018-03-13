#include "MainAppUIHolder.h"
#include "screens/WaitScreen.h"
#include "screens/DetectScreen.h"
#include "screens/ResultScreen.h"

using namespace bbrother;

MainAppUIHolder::MainAppUIHolder()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "MainAppUIHolder init");
	Screens.push_back(bbrother::BaseScreenPtr(new BaseScreen()));
	Screens.push_back(bbrother::BaseScreenPtr(new WaitScreen()));
	Screens.push_back(bbrother::BaseScreenPtr(new DetectScreen()));
	Screens.push_back(bbrother::BaseScreenPtr( new ResultScreen()));
	currentScreen = Screens[0];
}

void MainAppUIHolder::update()
{
	currentScreen->update();
}

void MainAppUIHolder::draw()
{
	currentScreen->draw();
}

void MainAppUIHolder::setter(ScreenState _state)
{
	currentScreen = Screens[static_cast<int>(_state)];
}

MainAppUIHolder::~MainAppUIHolder()
{

}
