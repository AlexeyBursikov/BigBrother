#pragma once
#include "ofMain.h"
#include "../../config/Config.h"

namespace bbrother
{
	typedef ofPtr<class FaceSearcher> FaceSearcherPtr;

	class FaceSearcher
	{
	public:	
		FaceSearcher();
		
		virtual void init(ConfigPtr config) = 0;
		virtual void update() = 0;		
		virtual ~FaceSearcher();
	};
}
