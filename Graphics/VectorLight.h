#pragma once
#include "Light.h"
#include <GL\glut.h>

class VectorLight : public Light {
public:
	VectorLight(float x, float y, float z, GLenum lamp) : Light(x, y, z, lamp, false, 0.1) {}
	void draw() override;
};

