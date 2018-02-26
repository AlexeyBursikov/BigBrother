#pragma once
#include "ofMain.h"
#include "screens/BaseScreen.h"

namespace bbrother
{
	typedef ofPtr<class MainAppUIHolder> MainAppUIHolderPtr;

	class MainAppUIHolder
	{
	public:
		MainAppUIHolder();
		virtual void update();
		virtual void draw();

		virtual ~MainAppUIHolder();

	private:
		BaseScreenPtr currentScreen;
	};
}

