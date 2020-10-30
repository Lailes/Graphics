#include "DotLight.h"

void DotLight::draw() {
	if (!display) return;

	Light::draw();

	glEnable(lamp);
	GLfloat diffuse[] = { lightCharacteristic->diffuseRGB[0], lightCharacteristic->diffuseRGB[1], lightCharacteristic->diffuseRGB[2] , 1.0 };
	GLfloat ambient[] = { lightCharacteristic->ambientRGB[0], lightCharacteristic->ambientRGB[1], lightCharacteristic->ambientRGB[2] , 1.0 };
	GLfloat specular[] = { lightCharacteristic->specularRGB[0], lightCharacteristic->specularRGB[1], lightCharacteristic->specularRGB[2] , 1.0 };
	GLfloat light_position[] = { x, y, z, 1.0 };

	glLightfv(lamp, GL_AMBIENT, ambient);
	glLightfv(lamp, GL_DIFFUSE, diffuse);
	glLightfv(lamp, GL_SPECULAR, specular);
	glLightfv(lamp, GL_POSITION, light_position);

	if (decay) {
		glLightf(lamp, GL_CONSTANT_ATTENUATION, 0.0);
		glLightf(lamp, GL_LINEAR_ATTENUATION, 0.2);
		glLightf(lamp, GL_QUADRATIC_ATTENUATION, 0.4);
	}
}
