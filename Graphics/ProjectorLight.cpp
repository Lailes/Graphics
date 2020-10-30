#include "ProjectorLight.h"

void ProjectorLight::draw() {
	if (!display) return;
	Light::draw();

	GLfloat light4_position[] = { x, y, z, 1.0 };
	GLfloat light4_spot_direction[] = { directionX, directionY, directionY };

	glEnable(lamp);

	GLfloat diffuse[] = { lightCharacteristic->diffuseRGB[0], lightCharacteristic->diffuseRGB[1], lightCharacteristic->diffuseRGB[2] , 1.0 };
	GLfloat ambient[] = { lightCharacteristic->ambientRGB[0], lightCharacteristic->ambientRGB[1], lightCharacteristic->ambientRGB[2] , 1.0 };
	GLfloat specular[] = { lightCharacteristic->specularRGB[0], lightCharacteristic->specularRGB[1], lightCharacteristic->specularRGB[2] , 1.0 };
	glLightfv(lamp, GL_DIFFUSE, diffuse);
	glLightfv(lamp, GL_AMBIENT, ambient);
	glLightfv(lamp, GL_SPECULAR, specular);
	glLightf(lamp, GL_SPOT_CUTOFF, angle);
	glLightfv(lamp, GL_SPOT_DIRECTION, light4_spot_direction);
	if (exponent != 0.0) {
		glLightf(lamp, GL_SPOT_EXPONENT, exponent);
	}
	glLightfv(lamp, GL_POSITION, light4_position);

}
