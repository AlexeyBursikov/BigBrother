#include "TestFacePlusPlusInterfaceLayout.h"

using namespace bbrother;

TestFacePlusPlusInterfaceLayout::TestFacePlusPlusInterfaceLayout()
{
	ofLog( ofLogLevel::OF_LOG_NOTICE, "Face++ TestInterfaceLayout init");

	screen1btn = ofPtr<ofxDatGuiButton>( new ofxDatGuiButton("Open photo"));
	screen1btn->onButtonEvent(this, &TestFacePlusPlusInterfaceLayout::screen1ButtonClicked);
	components.push_back(screen1btn);

	statusLabel = ofPtr<ofxDatGuiLabel>(new ofxDatGuiLabel("status"));
	components.push_back(statusLabel);

	faceDetector = ofPtr<FaceDetector>(new FacePlusPlusDetector());
	faceDetector->init(config);

	setPosition(ofPoint(100, 40));
	std::cout << "const";
	ofAddListener(faceDetector->photoProcessStatusEvent, this, &TestFacePlusPlusInterfaceLayout::statusChanged);
	std::cout << "added";
}

void TestFacePlusPlusInterfaceLayout::setConfig(ConfigPtr config) 
{
	this->config = config;
}

void TestFacePlusPlusInterfaceLayout::open()
{
	ofFileDialogResult openFileResult = ofSystemLoadDialog("Select a jpg or png");

	if (openFileResult.bSuccess)
	{
		ofLog(ofLogLevel::OF_LOG_NOTICE, "User selected a file");
		//@todo userSelect file notify
		faceDetector->processImage(openFileResult.filePath);
	}
	else
	{
		ofLog(ofLogLevel::OF_LOG_NOTICE, "User hit cancel");
	}
}

void TestFacePlusPlusInterfaceLayout::statusChanged(FaceDetector::PhotoProcessStatus& status)
{
	string statusText = faceDetector->getTextPhotoProcessStatus(status);	
	statusLabel->setLabel(statusText);
}

void TestFacePlusPlusInterfaceLayout::update()
{
	TestInterfaceLayout::update();
}

void TestFacePlusPlusInterfaceLayout::draw()
{
	TestInterfaceLayout::draw();
}

void TestFacePlusPlusInterfaceLayout::screen1ButtonClicked(ofxDatGuiButtonEvent event)
{
	open();
}