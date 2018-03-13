#pragma once
#include "ofMain.h"

namespace bbrother
{
	typedef ofPtr<class BaseScreen> BaseScreenPtr;

	class BaseScreen
	{
	public:
		BaseScreen();
		virtual void update();
		virtual void draw();

		virtual ~BaseScreen();
		ofTrueTypeFont font;
	};
}

