#pragma once
#include "ofMain.h"
#include "Tracker.h"

namespace bbrother
{
	typedef ofPtr<class KinectTracker> KinectTrackerPtr;

	class KinectTracker: public Tracker
	{
	public:
		KinectTracker();
		virtual void update() override;
		virtual void draw() override;	

		virtual ~KinectTracker();
	};
}

