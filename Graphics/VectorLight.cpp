#include "VectorLight.h"

void VectorLight::draw() {
	if (!display) return;
	Light::draw();
	GLfloat colorSpecs[] = { r, g, b, 1.0 };
	GLfloat position[] = { x, y, z, 0.0 };

	glEnable(lamp);
	glLightfv(lamp, GL_DIFFUSE, colorSpecs);
	glLightfv(lamp, GL_POSITION, position);
}
