#pragma once
#include "ofMain.h"
#include "../../abstract/FaceDetector.h"
#include "../../faceplusplus/FacePlusPlusTypes.h"
#include <json/json.h>

namespace bbrother 
{
	class JsonParserFaceplusPlus
	{
	public:
		JsonParserFaceplusPlus(const string& json);
		bool parse();
		bool valid();
		bool parseSuccess() const;
		FacePtr getFace() const;

	private:
		void setAttributes(FacePtr face, Json::Value faces);
		void setFaceRectangle(FacePtr face, Json::Value faces);
		void setFaceToken(FacePtr face, Json::Value faces);

		Json::Reader reader;
		Json::Value root;
		bool isValid;

		FacePtr currentFace;
		bool isParseSuccess;
	};
}