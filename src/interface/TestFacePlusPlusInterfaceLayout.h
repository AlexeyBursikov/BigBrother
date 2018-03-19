#pragma once
#include "TestInterfaceLayout.h"
#include "ofMain.h"
#include <../facedetector/FaceDetector.h>
#include <../facedetector/faceplusplus/FacePlusPlusDetector.h>


namespace bbrother {
	typedef ofPtr<class TestFacePlusPlusInterfaceLayout> TestFacePlusPlusInterfaceLayoutPtr;

	class TestFacePlusPlusInterfaceLayout : public TestInterfaceLayout {
	public:
		TestFacePlusPlusInterfaceLayout();
		void Open();
		virtual void setConfig( ConfigPtr config_ ) override;
		virtual void update() override;
		virtual void draw() override;

	private:
		ConfigPtr config;
		ofPtr<ofxDatGuiButton> screen1btn;
		ofPtr<ofxDatGuiLabel> status_label;
		ofPtr<FaceDetector> face_detector;

		void screen1ButtonClicked( ofxDatGuiButtonEvent event );
		void statusChanged( FaceDetector::Status& status );
	};
}