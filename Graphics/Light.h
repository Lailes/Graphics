#pragma once
#include <GL\glut.h>

#include "SceneObject.h"

class Light : public SceneObject {
protected:
	GLenum lamp;
	float r, g, b;  // light color
	bool decay = false;
	bool drawMark = false;
	float markSize;
	bool bindScene = false;

public:
	Light(float x, float y, float z, GLenum lamp, bool drawMark, float markSize): SceneObject(x,y,z) {
		this->drawMark = drawMark;
		this->markSize = markSize;
	}
	Light(float x, float y, float z, GLenum lamp) : Light(x, y, z, lamp, true, 0.02) {}

	virtual void bindScene(bool bind) {
		bindScene = bind;
	}
	virtual void turnDecay(bool decay) {
		this->decay = decay;
	}

	void setColor(float r, float g, float b) {
		this->r = r;
		this->g = g;
		this->b = b;
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

