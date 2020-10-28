#pragma once

#include <functional>

class SceneObject {
protected:
	float x, y, z;
	float startX, startY, startZ;
	std::function<void(unsigned char&, int&, int&, SceneObject*)> processFunction;
	std::function<void(SceneObject*)> restoreDefaultsFunction;
	bool display = true;

public:
	SceneObject(float x, float y, float z) {
		startX = this->x = x;
		startY = this->y = y;
		startZ = this->z = z;
	}

	virtual void setPosition(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
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
	virtual void setRestoreFunc(std::function<void(SceneObject*)> func) {
		restoreDefaultsFunction = func;
	}
	virtual void restoreDefaults() {
		if (restoreDefaultsFunction) {
			restoreDefaultsFunction(this);
		}
	}
	virtual void setDefaultPosition() {
		x = startX;
		y = startY;
		z = startZ;
		draw();
	}
	virtual void visibilty(bool visible) {
		this->display = visible;
	}
	virtual bool isVisible() {
		return display;
	}
};

