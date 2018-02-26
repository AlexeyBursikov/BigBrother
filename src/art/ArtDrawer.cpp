#include "ArtDrawer.h"

using namespace bbrother;

ArtDrawer::ArtDrawer()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Art Drawer init");

}

void ArtDrawer::update()
{
	
}

void ArtDrawer::draw()
{
	ofSetColor(ofFloatColor(1, 0, 0));

	float i = 0;
	ofPolyline line;

	while (i < TWO_PI)
	{
		float r = (2 - 2 * sin(i) + sin(i)*sqrt(abs(cos(i))) / (sin(i) + 1.4)) * -80;
		float x = ofGetWidth() / 2 + cos(i) * r;
		float y = ofGetHeight() / 2 + sin(i) * r;
		line.addVertex(ofVec2f(x, y));
		i += 0.005*HALF_PI*0.5;
	}
	line.close();
	line.draw();
}

ArtDrawer::~ArtDrawer()
{

}
