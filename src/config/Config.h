#pragma once
#include "ofMain.h"

namespace bbrother
{
	typedef shared_ptr<class Config> ConfigPtr;

	class Config
	{
	public:
		Config();

		ofEvent<void> loadCompleteEvent;

		virtual void load();

		virtual ~Config();
	};
}

