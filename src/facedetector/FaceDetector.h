#pragma once
#include "ofMain.h"

namespace bbrother
{
	typedef ofPtr<class FaceDetector> FaceDetectorPtr;

	class FaceDetector
	{
	public:
		FaceDetector();
		virtual ~FaceDetector();
	};
}

