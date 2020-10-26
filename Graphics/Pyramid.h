#pragma once
#include "SceneObject.h"

class Pyramid : public SceneObject {
private:
	float edgeSize;

public:
	Pyramid(float x0, float y0, float z0, float edgeSize = 0.5) : SceneObject(x0, y0, z0) {
		this->x = x0;
		this->y = y0;
		this->z = z0;
		this->edgeSize = edgeSize;
	}

	void draw() override;
};

