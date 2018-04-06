#pragma once
#include "ofMain.h"
#include "../abstract/FaceSearcher.h"
#include "FacePlusPlusTypes.h"

#include "../../tools/http/ofxHttpUtils.h"
#include "../../tools/http/ofxHttpTypes.h"

namespace bbrother
{
	typedef ofPtr<class FacePlusPlusSearcher> FacePlusPlusSearcherPtr;

	class FacePlusPlusSearcher : public FaceSearcher
	{
	public:
		FacePlusPlusSearcher();
		virtual void init(ConfigPtr config) override;
		virtual void update() override;
		virtual ~FacePlusPlusSearcher();
	
	};
}

