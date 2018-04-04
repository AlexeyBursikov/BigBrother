#pragma once

#include "ofMain.h"
#include "../config/Config.h"
#include "../tools/http/ofxHttpTypes.h"
#include "../tools/http/ofxHttpUtils.h"

namespace bbrother
{
	typedef ofPtr<class FamilyBaseRequestHandler> FamilyBaseRequestHandlerPtr;

	class FamilyBaseRequestHandler
	{
	public:		
		FamilyBaseRequestHandler();
		virtual ~FamilyBaseRequestHandler();

		void init(ConfigPtr config);
		void oathRequest();
		void getUsersRequest();
		void createUserRequest(const string& name, const string& masterToken);

		friend class JsonFamilyParser;

	private:
		enum class FamilyRequest
		{
			None,
			Oath,
			GetUsers,
			CreateUser
		};

		enum class HTTPRequestMethod
		{
			GET,
			POST			
		};

		struct OathRequestData
		{
			string grantType;
			int clientId;
			string clientSecret;
			string username;
			string password;
		};

		struct RequestAccessData
		{
			string accessToken;
			//...
		};

		struct RequestParam
		{
			RequestParam(const string& key, const string& value)
			{
				this->key = key;
				this->value = value;
			}
			string key;
			string value;
		};

		typedef RequestParam HeaderParam;
		
		RequestAccessData requestAccessData;
		OathRequestData oathRequestData;
		FamilyRequest requestType;
		string baseUrl;
		ofxHttpUtils httpUtils;

		string getRequestUrl(FamilyRequest request) const;
		vector<HeaderParam> getOathHeaders() const;
		void makeRequest(const string& Url, HTTPRequestMethod requestMethod, const vector<RequestParam>& requestParams, const vector<HeaderParam>& headerParams);
		void onServerResponse(ofxHttpResponse& response);
	};
}
