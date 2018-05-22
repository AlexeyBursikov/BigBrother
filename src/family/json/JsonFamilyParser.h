#pragma once
#include "ofMain.h"
#include "../FamilyBaseRequestHandler.h"
#include <json/json.h>

namespace bbrother 
{	
	class JsonFamilyParser
	{
	public:
		JsonFamilyParser(const string& json);
		bool valid();
		bool parseOath(FamilyBaseRequestHandler::RequestAccessData& requestAccessData);

	private:
		Json::Reader reader;
		Json::Value root;
		bool isValid;
		bool isParseSuccess;
	};
}