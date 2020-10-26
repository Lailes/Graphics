#pragma once
#include <functional>
#include <GL\glut.h>
#include "SceneObject.h"

class Cube : public SceneObject {
private:
	float edgeSize;

public:
	Cube(float x0, float y0, float z0, float edgeSize = 0.5) {
		this->x = x0;
		this->y = y0;
		this->z = z0;
		this->edgeSize = edgeSize;
	}

	void draw() override;

	void setEdgeSize(float size);
};

