#include "Config.h"

using namespace bbrother;

Config::Config()
{
	setConfigPath();
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Config init");
}

void Config::load()
{
	if (element.openLocal(path)) 
	{
		text = element.getRawString();
		ofLog(ofLogLevel::OF_LOG_NOTICE, text);
		ofNotifyEvent(loadCompleteEvent, this);
	}
	ofNotifyEvent(loadErrorEvent, this);
}

void Config::setConfigPath(const std::string _path)
{
	path = _path;
}

Config::~Config()
{

}
