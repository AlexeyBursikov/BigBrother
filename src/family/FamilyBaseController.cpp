#include "FamilyBaseController.h"

using namespace bbrother;

FamilyBaseController::FamilyBaseController()
{
	familyBaseRequestHandler = FamilyBaseRequestHandlerPtr(new FamilyBaseRequestHandler());
	
}

void FamilyBaseController::init(ConfigPtr config)
{
	familyBaseRequestHandler->init(config);
	familyBaseRequestHandler->oathRequest();
	//familyBaseRequestHandler->oathRequest();
	//familyBaseRequestHandler->oathRequest();
	//familyBaseRequestHandler->oathRequest();
}

void FamilyBaseController::update()
{
	familyBaseRequestHandler->update();
}

FamilyBaseController::~FamilyBaseController()
{

}