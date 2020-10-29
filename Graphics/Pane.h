#pragma once

#include <vector>

#include "Shape.h"

struct Dot {
	float xf, yf, zf;
	Dot(float x, float y, float z): xf(x), yf(y), zf(z) {}
};

class Pane : public Shape {
protected:
	std::vector<Dot*> dots;
	float r, g, b;

public:
	Pane(float rColor, float gColor, float bColor) : r(rColor), g(gColor), b(bColor), Shape(0, 0, 0) {}
	void addVertex(float x, float y, float z);
	void draw() override;
	~Pane();
};

