#pragma once
#include "ofMain.h"
#include "screens/BaseScreen.h"
#include <vector>

namespace bbrother
{
	typedef ofPtr<class MainAppUIHolder> MainAppUIHolderPtr;

	enum class ScreenState
	{
		None,
		Wait,
		Detect,
		Result
	};

	class MainAppUIHolder
	{
	public:
		MainAppUIHolder();
		virtual void update();
		virtual void draw();
		virtual void setter(ScreenState _state);

		virtual ~MainAppUIHolder();

	private:
		BaseScreenPtr currentScreen;
		vector<BaseScreenPtr> Screens;
	};
}

