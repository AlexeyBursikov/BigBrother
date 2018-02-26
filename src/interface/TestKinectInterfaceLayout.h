#pragma once
#include "ofMain.h"
#include "TestInterfaceLayout.h"
#include "ofxDatGui.h"

namespace bbrother
{
	typedef ofPtr<class TestKinectInterfaceLayout> TestKinectInterfaceLayoutPtr;

	class TestKinectInterfaceLayout : public TestInterfaceLayout
	{
	public:
		TestKinectInterfaceLayout();

		virtual void update();
		virtual void draw();
		virtual ~TestKinectInterfaceLayout();

	private:
		ofPtr<ofxDatGuiButton> kinectStartButton;
		void kinectStartButtonClicked(ofxDatGuiButtonEvent event);
	};
}

