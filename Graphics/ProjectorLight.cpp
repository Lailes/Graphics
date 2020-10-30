#include "ProjectorLight.h"

void ProjectorLight::draw() {
	if (!display) return;
	Light::draw();

	GLfloat diffuse[] = { lightCharacteristic->diffuseRGB[0], lightCharacteristic->diffuseRGB[1], lightCharacteristic->diffuseRGB[2]  };
	GLfloat ambient[] = { lightCharacteristic->ambientRGB[0], lightCharacteristic->ambientRGB[1], lightCharacteristic->ambientRGB[2] };
	GLfloat specular[] = { lightCharacteristic->specularRGB[0], lightCharacteristic->specularRGB[1], lightCharacteristic->specularRGB[2] };
	GLfloat position[] = { x, y, z, 1.0 };
	GLfloat light3_spot_direction[] = { directionX, directionY, directionZ };


	glEnable(lamp);
	glLightfv(lamp, GL_DIFFUSE, diffuse);
	glLightfv(lamp, GL_AMBIENT, ambient);
	glLightfv(lamp, GL_SPECULAR, specular);
	glLightfv(lamp, GL_POSITION, position);
	glLightf(lamp, GL_SPOT_CUTOFF, angle/2);
	glLightfv(lamp, GL_SPOT_DIRECTION, light3_spot_direction);

}
