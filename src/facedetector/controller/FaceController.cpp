#include "FaceController.h"

using namespace bbrother;

FaceController::FaceController()
{
	familyBaseController = FamilyBaseControllerPtr(new FamilyBaseController());
	facePlusPlusDetector = FacePlusPlusDetectorPtr(new FacePlusPlusDetector());
	facePlusPlusComparer = FacePlusPlusComparerPtr(new FacePlusPlusComparer());	
}

void FaceController::init(ConfigPtr config)
{
	familyBaseController->init(config);
	facePlusPlusDetector->init(config);
	facePlusPlusComparer->init(config);

	facePlusPlusDetector->processImage("face.jpg");
	//facePlusPlusDetector->processImage("face.jpg");
	//facePlusPlusDetector->processImage("face.jpg");
	//facePlusPlusDetector->processImage("face.jpg");
	//facePlusPlusDetector->processImage("face.jpg");
}

void FaceController::update()
{
	facePlusPlusDetector->update();
	familyBaseController->update();
	facePlusPlusComparer->update();
}

void FaceController::newPersonAppear(PersonPtr person)
{
	//facePlusPlusDetector->searchFace();
}

void FaceController::onFaceDetect()
{
	//familyBigBrotherController->getFaceSets();
	//facePlusPlusComparer->searchInFaceSet();
}

void FaceController::onFaceNotDetect()
{

}

void FaceController::onFaceDetectorError()
{

}

void FaceController::onFaceFindInFaceSet()
{
	//familyBigBrotherController->getUser();
	//notify userInfo
}

void FaceController::onFaceNotFindInFaceSet()
{

}

void FaceController::onFaceComparerError()
{

}

FaceController::~FaceController()
{

}