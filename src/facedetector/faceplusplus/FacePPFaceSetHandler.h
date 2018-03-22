#pragma once
#include "ofMain.h"
#include "../FaceDetector.h"
#include "FacePlusPlusTypes.h"

#include "../../tools/http/ofxHttpUtils.h"
#include "../../tools/http/ofxHttpTypes.h"

namespace bbrother
{
	typedef ofPtr<class FacePPFaceSetHandler> FacePPFaceSetHandlerPtr;

	class FacePPFaceSetHandler : public FaceDetector
	{
	public:
		FacePPFaceSetHandler();
		virtual void init(ConfigPtr config) override;
		virtual ~FacePPFaceSetHandler();
	private:
		ofxHttpUtils httpUtils;

		void makeRequest(const string& FACE_URL, const string& API_KEY, const string& API_SECRET, const string& filePath);
	
		string FACE_URL;
		string API_KEY;
		string API_SECRET;
		string path;
	};
}

