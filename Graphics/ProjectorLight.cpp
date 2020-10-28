#include "ProjectorLight.h"

void ProjectorLight::draw() {
	if (!display) return;
	Light::draw();

	GLfloat light4_diffuse[] = { r, g, b, 1.0 };
	GLfloat light4_position[] = { x, y, z, 1.0 };
	GLfloat light4_spot_direction[] = { directionX, directionY, directionY };

	glEnable(lamp);
	glLightfv(lamp, GL_DIFFUSE, light4_diffuse);
	glLightfv(lamp, GL_POSITION, light4_position);
	glLightf(lamp, GL_SPOT_CUTOFF, angle);
	glLightfv(lamp, GL_SPOT_DIRECTION, light4_spot_direction);
	if (exponent != 0.0) {
		glLightf(lamp, GL_SPOT_EXPONENT, exponent);
	}
}
