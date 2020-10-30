#pragma once
#include <GL\glut.h>

#include "LightCharacteristic.h"
#include "SceneObject.h"

class Light : public SceneObject {
protected:
	GLenum lamp;
	LightCharacteristic* lightCharacteristic;
	LightCharacteristic* defaultCharacteristic;
	bool decay = false;
	bool drawMark = false;
	float markSize;

public:
	Light(float x, float y, float z, GLenum lamp, bool drawMark, float markSize);
	Light(float x, float y, float z, GLenum lamp) : Light(x, y, z, lamp, true, 0.02) {}

	virtual void turnDecay(bool decay) {
		this->decay = decay;
	}

	void setLigthCharacteristic(LightCharacteristic* material) {
		lightCharacteristic = material;
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

public:

	~Light() {
		delete lightCharacteristic;
		delete defaultCharacteristic;
	}
};

