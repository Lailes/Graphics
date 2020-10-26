#include "DotLight.h"

void DotLight::draw() {
	if (!display) return;
	Light::draw();
	GLfloat colorSpecs[] = { r, g, b, 1.0 };
	GLfloat position[] = { x, y, z, 1.0 };

	glEnable(lamp);
	glLightfv(lamp, GL_DIFFUSE, colorSpecs);
	glLightfv(lamp, GL_POSITION, position);

	if (decay) {
		glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 0.0);
		glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.2);
		glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.4);
	}
}
