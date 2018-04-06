#include "FaceDetector.h"

using namespace bbrother;

FaceDetector::FaceDetector()
{
	
}

void FaceDetector::setPhotoProcessStatus(PhotoProcessStatus status)
{
	photoProcessStatus = status;
	ofNotifyEvent(photoProcessStatusEvent, photoProcessStatus);
}

string FaceDetector::getTextPhotoProcessStatus() const
{
	return getTextPhotoProcessStatus(photoProcessStatus);
}

string FaceDetector::getTextPhotoProcessStatus(PhotoProcessStatus status) const
{
	string statusText = "Undefine";
	switch (status)
	{
	case FaceDetector::PhotoProcessStatus::Detect:
		statusText = "Detect";
		break;
	case FaceDetector::PhotoProcessStatus::NotDetect:
		statusText = "Not Detect";
		break;
	case FaceDetector::PhotoProcessStatus::Process:
		statusText = "Process";
		break;
	case FaceDetector::PhotoProcessStatus::WaitForPhoto:
		statusText = "Wait For Photo";
		break;
	}

	return statusText;
}

FaceDetector::~FaceDetector()
{

}
