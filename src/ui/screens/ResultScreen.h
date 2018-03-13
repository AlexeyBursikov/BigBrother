#pragma once
#include "ofMain.h"
#include "BaseScreen.h"

namespace bbrother
{
	typedef ofPtr<class  ResultScreen>  ResultScreenPtr;

	class  ResultScreen : public BaseScreen
	{
	public:
		ResultScreen();
		virtual void update();
		virtual void draw();

		virtual ~ResultScreen();

	private:
		ofImage image;
	};
}