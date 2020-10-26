#include "DotLight.h"

void DotLight::draw() {
	if (!display) return;
	Light::draw();
	GLfloat colorSpecs[] = { r, g, b, 1.0 };
	GLfloat position[] = { x, y, z, 1.0 };
	GLfloat mass[] = { 1.0, 1.0, 1.0, 1.0 };

	glEnable(lamp);
	glLightfv(lamp, GL_DIFFUSE, colorSpecs);
	glLightfv(lamp, GL_SPECULAR, mass);
	glLightfv(lamp, GL_POSITION, position);

	if (decay) {
		glLightf(lamp, GL_CONSTANT_ATTENUATION, 0.0);
		glLightf(lamp, GL_LINEAR_ATTENUATION, 0.2);
		glLightf(lamp, GL_QUADRATIC_ATTENUATION, 0.4);
	}
}
