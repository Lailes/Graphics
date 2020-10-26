#pragma once
#include "Light.h"
class ProjectorLight : public Light {
protected:
	float directionX, directionY, directionZ;
	float angle;
	float exponent = 0.0;

public:
	ProjectorLight(float x, float y, float z, float r, float g, float b, GLenum lamp, bool drawMark, float markSize) : Light(x, y, z, r, g, b, lamp, drawMark, markSize) {
	}
	ProjectorLight(float x, float y, float z, float r, float g, float b, GLenum lamp) : Light(x, y, z, r, g, b, lamp) {}

	void setDirection(float x, float y, float z) {
		directionX = x;
		directionY = y;
		directionZ = z;
	}

	void setExponent(float exp) {
		this->exponent = exp;
	}

	void draw() override;
};

