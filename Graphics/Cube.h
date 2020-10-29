#pragma once
#include <functional>
#include <GL\glut.h>
#include "Shape.h"

class Cube : public Shape {
private:
	float edgeSize;

public:
	Cube(float x0, float y0, float z0, float edgeSize = 0.5): Shape(x0, y0, z0) {
		this->x = x0;
		this->y = y0;
		this->z = z0;
		this->edgeSize = edgeSize;
	}

	void draw() override;
};

