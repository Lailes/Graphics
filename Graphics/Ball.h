#pragma once
#include "Shape.h"


class Ball : public Shape {
private:
	float radius;

public:
	Ball(float x0, float y0, float z0, float radius = 0.1): Shape(x0, y0, z0){
		this->x = x0;
		this->y = y0;
		this->z = z0;
		this->radius = radius;
	}

	void draw() override;
};

