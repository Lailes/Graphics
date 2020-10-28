#pragma once
#include "Light.h"
class ProjectorLight : public Light {
protected:
	float directionX, directionY, directionZ;
	float angle;
	float exponent = 0.0;

public:
	ProjectorLight(float x, float y, float z, GLenum lamp, bool drawMark, float markSize) : Light(x, y, z, lamp, drawMark, markSize) {
	}
	ProjectorLight(float x, float y, float z, GLenum lamp) : Light(x, y, z, lamp) {}

	void setDirection(float x, float y, float z) {
		directionX = x;
		directionY = y;
		directionZ = z;
	}

	void setExponent(float exp) {
		this->exponent = exp;
	}

	void setAngle(float angle) {
		this->angle = angle;
	}

	void draw() override;
};

