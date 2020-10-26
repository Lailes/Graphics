#pragma once
#include <GL\glut.h>

#include "SceneObject.h"

class Light : public SceneObject {
protected:
	GLenum lamp;
	float r, g, b;  // light color
	bool display = false;
	bool decay = false;
	bool drawMark = false;
	float markSize;

public:
	Light(float x, float y, float z, float r, float g, float b, GLenum lamp, bool drawMark, float markSize);
	virtual void turnDecay(bool decay) {
		this->decay = decay;
	}

	virtual void draw() override;

	virtual void turn(bool display) {
		this->display = display;
		if (display) {
			draw();
		} else {
			glDisable(lamp);
		}
	}

	virtual bool isOn() {
		return display;
	}
};

