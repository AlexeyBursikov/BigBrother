#pragma once
#include "ofMain.h"
#include "../abstract/FaceComparer.h"
#include "FacePlusPlusTypes.h"

#include "../../tools/http/ofxHttpUtils.h"
#include "../../tools/http/ofxHttpTypes.h"

namespace bbrother
{
	typedef ofPtr<class FacePlusPlusComparer> FacePlusPlusComparerPtr;

	class FacePlusPlusComparer : public FaceComparer
	{
	public:
		FacePlusPlusComparer();
		virtual void init(ConfigPtr config) override;
		virtual void update() override;
		virtual ~FacePlusPlusComparer();
	
	};
}

