#pragma once

#include "ofMain.h"
#include "../../family/FamilyBaseController.h"
#include "../faceplusplus/FacePlusPlusDetector.h"
#include "../faceplusplus/FacePlusPlusComparer.h"

namespace bbrother
{
	typedef ofPtr<class FaceController> FaceControllerPtr;

	class FaceController //: public FaceDetector
	{
	public:
		FaceController();
		virtual ~FaceController();

		virtual void init(ConfigPtr config);
		virtual void update();

	private:
		FamilyBaseControllerPtr familyBaseController;
		FacePlusPlusDetectorPtr facePlusPlusDetector;
		FacePlusPlusComparerPtr facePlusPlusComparer;

		void findUser();
		void onFaceDetect();
		void onFaceNotDetect();
		void onFaceDetectorError();

		void onFaceFindInFaceSet();

		void onFaceNotFindInFaceSet();
		void onFaceComparerError();
	};
}



