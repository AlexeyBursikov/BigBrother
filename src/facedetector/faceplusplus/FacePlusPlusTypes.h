#pragma once
#include "ofMain.h"

namespace bbrother
{
	struct FaceRectangle
	{
		FaceRectangle(float t, float l, float w, float h);
		FaceRectangle();

		float top;
		float left;
		float width;
		float height;
	};

	struct FaceAttributes
	{
		string gender;
		int age;
		string ethnicity;
		//HeadPose headpose;
		//Beauty beauty;
		//Eyegaze eyegaze;
		void setBeauty(float maleScore, float femaleScore);
	};

	class Face
	{
		string token;
		vector<ofPoint> landmark;
		FaceAttributes attributes;
		FaceRectangle faceRectangle;

	public:
		Face();

		void setToken(const string& token);
		string getToken() const;

		void setFaceRectangle(const FaceRectangle& faceRectangle);
		FaceRectangle getFaceRectangle() const;

		void setLandmark(const vector<ofPoint>& landmark);
		vector<ofPoint> getLandmark() const;

		void setAttributes(const FaceAttributes& attributes);
		FaceAttributes getAttributes() const;

		/*Beauty getBeauty() const;*/

	};
}

