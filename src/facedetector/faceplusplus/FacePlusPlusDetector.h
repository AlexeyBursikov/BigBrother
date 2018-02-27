#pragma once
#include "ofMain.h"
#include "../FaceDetector.h"
#include "FacePlusPlusTypes.h"

#include "../../tools/http/ofxHttpUtils.h"
#include "../../tools/http/ofxHttpTypes.h"

namespace bbrother
{
	typedef ofPtr<class FacePlusPlusDetector> FacePlusPlusDetectorPtr;

	class FacePlusPlusDetector : public FaceDetector
	{
	public:
		FacePlusPlusDetector();
		virtual ~FacePlusPlusDetector();

	private:
		Face face;

		ofxHttpUtils httpUtils;
		void makeRequest();
		void newResponse(ofxHttpResponse & response);
		
	};
}

