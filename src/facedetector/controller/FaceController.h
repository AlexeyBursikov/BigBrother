#pragma once

#include "ofMain.h"
#include "../../family/FamilyBaseController.h"
#include "../faceplusplus/FacePlusPlusDetector.h"
#include "../faceplusplus/FacePlusPlusComparer.h"
#include "../../person/Person.h"

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

		void newPersonAppear(PersonPtr person);

		ofEvent<PersonPtr> personFaceDetect;
		ofEvent<PersonPtr> personFaceNotDetect;
		ofEvent<PersonPtr> personFoundInFaceSet;
		ofEvent<PersonPtr> personNotFoundInFaceSet;
		ofEvent<PersonPtr> personFoundInFamilyBase;
		ofEvent<PersonPtr> personNotFoundInFamilyBase;

		ofEvent<void> serviceError;

	private:
		FamilyBaseControllerPtr familyBaseController;
		FacePlusPlusDetectorPtr facePlusPlusDetector;
		FacePlusPlusComparerPtr facePlusPlusComparer;

		
		void onFaceDetect();
		void onFaceNotDetect();
		void onFaceDetectorError();

		void onFaceFindInFaceSet();

		void onFaceNotFindInFaceSet();
		void onFaceComparerError();
	};
}



