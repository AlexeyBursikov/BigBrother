#include "JsonFamilyParser.h"

using namespace bbrother;

JsonFamilyParser::JsonFamilyParser(const string& json) :
	isParseSuccess(false)
{
	isValid = reader.parse(json, root);
}

bool JsonFamilyParser::valid()
{
	return isValid;
}


bool JsonFamilyParser::parseOath(FamilyBaseRequestHandler::RequestAccessData& requestAccessData)
{
	if(isValid)
	{ 
		try
		{		
			requestAccessData.accessToken = root["access_token"].asString();
			isParseSuccess = true;
		}
		catch(exception e) 
		{
			std::cout << "Error parsing...";
			std::cout << e.what();		
		}
	}

	return isParseSuccess;
}
