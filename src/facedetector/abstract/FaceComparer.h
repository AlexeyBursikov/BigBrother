#pragma once
#include "ofMain.h"
#include "../../config/Config.h"

namespace bbrother
{
	typedef ofPtr<class FaceComparer> FaceComparerPtr;

	class FaceComparer
	{
	public:	
		FaceComparer();
		
		virtual void init(ConfigPtr config) = 0;
		virtual void update() = 0;		
		virtual ~FaceComparer();
	};
}
