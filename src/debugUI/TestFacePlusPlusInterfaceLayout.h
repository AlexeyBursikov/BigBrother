#pragma once
#include "TestInterfaceLayout.h"
#include "ofMain.h"
#include "../facedetector/abstract/FaceDetector.h"
#include "../facedetector/faceplusplus/FacePlusPlusDetector.h"

namespace bbrother
{
	typedef ofPtr<class TestFacePlusPlusInterfaceLayout> TestFacePlusPlusInterfaceLayoutPtr;

	class TestFacePlusPlusInterfaceLayout : public TestInterfaceLayout 
	{
	public:
		TestFacePlusPlusInterfaceLayout();
		void open();
		virtual void setConfig(ConfigPtr config) override;
		virtual void update() override;
		virtual void draw() override;

	private:
		ConfigPtr config;
		ofPtr<ofxDatGuiButton> screen1btn;
		ofPtr<ofxDatGuiLabel> statusLabel;
		ofPtr<FaceDetector> faceDetector;

		void screen1ButtonClicked(ofxDatGuiButtonEvent event);
		void statusChanged(FaceDetector::PhotoProcessStatus& status);
	};
}