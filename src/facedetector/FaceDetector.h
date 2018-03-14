#pragma once
#include "ofMain.h"
#include "../config/Config.h"

namespace bbrother
{
	typedef ofPtr<class FaceDetector> FaceDetectorPtr;

	class FaceDetector
	{
	public:
		FaceDetector();
		virtual void init( ConfigPtr config ) = 0;
		virtual ~FaceDetector();
		
	};
}

