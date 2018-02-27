#pragma once
#include "ofMain.h"
#include "FaceDetector.h"

namespace bbrother
{
	typedef ofPtr<class FacePlusPlusDetector> FacePlusPlusDetectorPtr;

	class FacePlusPlusDetector : public FaceDetector
	{
	public:
		FacePlusPlusDetector();
		virtual ~FacePlusPlusDetector();
	};
}

