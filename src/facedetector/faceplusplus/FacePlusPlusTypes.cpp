#include "FacePlusPlusTypes.h"

using namespace bbrother;

FaceRectangle::FaceRectangle(float t, float l, float w, float h)
	:top(t), left(l), width(w), height(h)
{

}

FaceRectangle::FaceRectangle()
{

}

void FaceAttributes::setBeauty(float maleScore, float femaleScore)
{
	//beauty.setMaleScore(maleScore);
	//beauty.setFemaleScore(femaleScore);
}

Face::Face()
{

}

void Face::setToken(const string& token)
{
	this->token = token;
}

string Face::getToken() const
{
	return token;
}

void Face::setFaceRectangle(const FaceRectangle& faceRectangle)
{
	this->faceRectangle = faceRectangle;
}

FaceRectangle Face::getFaceRectangle() const
{
	return faceRectangle;
}

void Face::setLandmark(const vector<ofPoint>& landmark)
{
	this->landmark = landmark;
}

vector<ofPoint> Face::getLandmark() const
{
	return landmark;
}

void Face::setAttributes(const FaceAttributes& attributes)
{
	this->attributes = attributes;
}

FaceAttributes Face::getAttributes() const
{
	return attributes;
}

/*Beauty Face::getBeauty() const
{
return attributes.beauty;
}*/
