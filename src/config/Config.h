#pragma once
#include "ofMain.h"
#include "ofxJSON.h"
#include <string>

namespace bbrother
{
	typedef shared_ptr<class Config> ConfigPtr;

	class Config
	{
	public:
		Config();

		ofEvent<void> loadCompleteEvent;
<<<<<<< Updated upstream

		virtual void load();
=======
		ofEvent<void> loadErrorEvent;
		
		virtual void load(); 
		virtual void setConfigPath(const string _path = "config.json");
>>>>>>> Stashed changes

		virtual ~Config();
	private:
		ofxJSONElement element;
		std::string path;
		std::string text;
	};
}

