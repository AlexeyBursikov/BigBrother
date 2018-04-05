#pragma once
#include "ofMain.h"
#include "FamilyBaseRequestHandler.h"

namespace bbrother
{
	typedef ofPtr<class FamilyBaseController> FamilyBaseControllerPtr;

	class FamilyBaseController
	{
	public:
		FamilyBaseController();
		virtual ~FamilyBaseController();

		virtual void init(ConfigPtr config);
		virtual void update();

	private:
		FamilyBaseRequestHandlerPtr familyBaseRequestHandler;
		

	};
}



