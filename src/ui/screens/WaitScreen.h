#pragma once
#include "ofMain.h"
#include "BaseScreen.h"

namespace bbrother
{
	typedef ofPtr<class WaitScreen> WaitScreenPtr;

	class WaitScreen : public BaseScreen
	{
	public:
		WaitScreen();
		virtual void update();
		virtual void draw();

		virtual ~WaitScreen();
	};
}

