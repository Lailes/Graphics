#pragma once

#include <vector>

#include "SceneObject.h"

struct Dot {
	float xf, yf, zf;
	Dot(float x, float y, float z): xf(x), yf(y), zf(z) {}
};

class Pane : public SceneObject {
protected:
	std::vector<Dot*> dots;
	float r, g, b;

public:
	Pane(float rColor, float gColor, float bColor) : r(rColor), g(gColor), b(bColor), SceneObject(0, 0, 0) {}
	void addDot(float x, float y, float z);
	void draw() override;

	~Pane();

};

