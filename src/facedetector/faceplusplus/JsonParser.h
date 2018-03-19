#pragma once
#include "ofMain.h"
#include "../FaceDetector.h"
#include "FacePlusPlusTypes.h"

#include <json/json.h>


namespace bbrother {
	class JsonParser {
	public:
		JsonParser( string json_str_ );
		Face* Parse();
		bool Valid();

	private:
		void setAttributes( Face* human, Json::Value faces );
		void setFaceRectangle( Face* human, Json::Value faces );
		void setFaceToken( Face* human, Json::Value faces );

		Json::Reader reader;
		Json::Value root;
		bool valid;
		string json_str;
	};
}