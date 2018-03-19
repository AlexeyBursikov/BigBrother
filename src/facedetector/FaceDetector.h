#pragma once
#include "ofMain.h"
#include "../config/Config.h"

namespace bbrother
{
	typedef ofPtr<class FaceDetector> FaceDetectorPtr;

	class FaceDetector {
	public:
		enum Status {
			WaitForPhoto,
			Process,
			Detect,
			NotDetect
		};

		FaceDetector();
		virtual void init( ConfigPtr config ) = 0;
		virtual void ProcessImage( string path ) = 0;
		virtual ~FaceDetector();
		Status test;
		ofEvent<Status> status_event;
	};
}

