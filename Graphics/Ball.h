#pragma once
#include "SceneObject.h"


class Ball : public SceneObject {
private:
	float radius;

public:
	Ball(float x0, float y0, float z0, float radius = 0.1): SceneObject(x0, y0, z0){
		this->x = x0;
		this->y = y0;
		this->z = z0;
		this->radius = radius;
	}

	void draw() override;
};

