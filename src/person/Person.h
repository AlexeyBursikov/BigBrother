#pragma once
#include "ofMain.h"

namespace bbrother
{
	typedef ofPtr<class Person> PersonPtr;

	struct FaceData
	{

	};

	struct KinectData
	{

	};

	class Person
	{
	public:
		Person();
		virtual ~Person();

	private:
		int id;
		KinectData kinectData;
		FaceData faceData;
	};
}

