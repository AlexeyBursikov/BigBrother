#pragma once

#include "ofMain.h"
#include "../config/Config.h"
#include "../tools/http/HttpService.h"
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
		virtual void update();

		friend class JsonFamilyParser;

	private:
		enum class FamilyRequest
		{
			None,
			Oath,
			GetUsers,
			CreateUser
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
		
		RequestAccessData requestAccessData;
		OathRequestData oathRequestData;
		FamilyRequest requestType;
		string baseUrl;
		HttpService httpService;

		string getRequestUrl(FamilyRequest request) const;
		vector<HttpService::HeaderParam> getOathHeaders() const;
		void onServerResponse(const string& response);
	};
}
