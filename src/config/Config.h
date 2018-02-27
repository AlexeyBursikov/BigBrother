#pragma once
#include "ofMain.h"

namespace bbrother
{
	typedef ofPtr<class Config> ConfigPtr;

	class Config
	{
	public:
		Config();

		ofEvent<void> loadCompleteEvent;

		virtual void load();

		virtual ~Config();
	};
}

