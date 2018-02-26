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

	typedef ofPtr<class TestInterfaceLayout> TestInterfaceLayoutPtr;

	class TestInterfaceLayout
	{
	public:
		TestInterfaceLayout();

		ofEvent<InterfaceEventType> InterfaceEvent;

		virtual void update() = 0;
		virtual void draw() = 0;
		virtual ~TestInterfaceLayout();

	private:
		// arts vector
	};
}

