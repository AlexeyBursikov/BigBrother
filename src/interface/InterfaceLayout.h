#pragma once
#include "ofMain.h"

namespace bbrother
{
	enum class InterfaceEventType
	{
		None,
		TrackingStart,
		TrackingStop,
		TryDetectHuman
	};

	typedef ofPtr<class InterfaceLayout> InterfaceLayoutPtr;

	class InterfaceLayout
	{
	public:
		InterfaceLayout();

		ofEvent<InterfaceEventType> InterfaceEvent;

		virtual void update() = 0;
		virtual void draw() = 0;
		virtual ~InterfaceLayout();

	private:
		// arts vector
	};
}

