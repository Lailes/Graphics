#pragma once
#include "Light.h"

class DotLight : public Light {

public:
	DotLight(float x, float y, float z, GLenum lamp, bool drawMark, float markSize) : Light(x, y, z, lamp, drawMark, markSize) {}
	DotLight(float x, float y, float z, GLenum lamp) : Light(x, y, z, lamp) {}
	void draw() override;
};

