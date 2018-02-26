#pragma once
#include "ofMain.h"
#include "InterfaceLayout.h"
#include "ofxDatGui.h"

namespace bbrother
{
	typedef ofPtr<class BigBrotherInterfaceLayout> BigBrotherInterfaceLayoutPtr;

	class BigBrotherInterfaceLayout : public InterfaceLayout
	{
	public:
		BigBrotherInterfaceLayout();

		virtual void update();
		virtual void draw();
		virtual ~BigBrotherInterfaceLayout();

	private:
		ofPtr<ofxDatGuiButton> kinectStartButton;
		void kinectStartButtonClicked(ofxDatGuiButtonEvent event);
	};
}

