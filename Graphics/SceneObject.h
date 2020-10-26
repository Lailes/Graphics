#pragma once

#include <functional>

class SceneObject {
protected:
	float x, y, z;
	std::function<void(unsigned char&, int&, int&, SceneObject*)> processFunction;

public:
	virtual void setPosition(float xPos, float yPos, float zPos) {
		x = xPos;
		y = yPos;
		z = zPos;
	}
	virtual void changeX(float delta) { x += delta; }
	virtual void changeY(float delta) {	y += delta; }
	virtual void changeZ(float delta) { z += delta; }

	virtual void draw() = 0;

	virtual void processInput(unsigned char key, int x, int y) {
		if (processFunction) {
			processFunction(key, x, y, this);
		}
	}
	virtual void setProcessFunc(std::function<void(unsigned char&, int&, int&, SceneObject*)> func) {
		processFunction = func;
	}
};

