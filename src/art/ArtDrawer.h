#pragma once
#include "ofMain.h"

namespace bbrother
{
	typedef ofPtr<class ArtDrawer> ArtDrawerPtr;

	class ArtDrawer
	{
	public:
		ArtDrawer();
		virtual void update();
		virtual void draw();

		virtual ~ArtDrawer();
	};
}

