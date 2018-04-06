#pragma once
#include "ofMain.h"
#include "screens/BaseScreen.h"
#include "../person/Person.h"

namespace bbrother
{
	typedef ofPtr<class ScreenController> ScreenControllerPtr;

	enum class ScreenState
	{
		None,
		Wait,
		Detect,
		Result
	};

	class ScreenController
	{
	public:
		ScreenController();
		virtual void update();
		virtual void draw();

		void newPersonAppear(PersonPtr person);
		virtual ~ScreenController();

	private:
		BaseScreenPtr currentScreen;
	};
}

