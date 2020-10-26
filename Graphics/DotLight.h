#pragma once
#include "Light.h"

class DotLight : public Light {

public:
	DotLight(float x, float y, float z, float r, float g, float b, GLenum lamp, bool drawMark, float markSize) : Light(x, y, z, r, g, b, lamp, drawMark, markSize) {}
	DotLight(float x, float y, float z, float r, float g, float b, GLenum lamp) : Light(x, y, z, r, g, b, lamp) {}
	void draw() override;
};

