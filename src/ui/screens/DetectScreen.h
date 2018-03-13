#pragma once
#include "ofMain.h"
#include "BaseScreen.h"

namespace bbrother
{
	typedef ofPtr<class DetectScreen> DetectScreenPtr;

	class DetectScreen : public BaseScreen
	{
	public:
		DetectScreen();
		virtual void update();
		virtual void draw();

		virtual ~DetectScreen();
	private:
		ofImage image;
	};
}