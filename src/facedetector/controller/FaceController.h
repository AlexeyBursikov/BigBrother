#pragma once

#include "ofMain.h"
#include "../../family/FamilyBaseController.h"
#include "../faceplusplus/FacePlusPlusDetector.h"
#include "../faceplusplus/FacePlusPlusSearcher.h"
#include "../../person/Person.h"

namespace bbrother
{
	typedef ofPtr<class FaceController> FaceControllerPtr;

	class FaceController
	{
	public:
		FaceController();
		virtual ~FaceController();

		virtual void init(ConfigPtr config);
		virtual void update();
	
		ofEvent<PersonPtr> personFaceDetect;
		ofEvent<PersonPtr> personFaceNotDetect;
		ofEvent<PersonPtr> personFoundInFaceSet;
		ofEvent<PersonPtr> personNotFoundInFaceSet;
		ofEvent<PersonPtr> personFoundInFamilyBase;
		ofEvent<PersonPtr> personNotFoundInFamilyBase;

		ofEvent<void> serviceError;

		void newPersonAppear(PersonPtr person);

	private:
		FamilyBaseControllerPtr familyBaseController;
		FacePlusPlusDetectorPtr facePlusPlusDetector;
		FacePlusPlusSearcherPtr facePlusPlusSearcher;
		
		void onFaceDetect(PersonPtr person);
		void onFaceNotDetect();
		void onFaceDetectorError();

		void onFaceFoundInFaceSet(PersonPtr person);
		void onFaceNotFoundInFaceSet();
		void onFaceSearchError();
	};
}
