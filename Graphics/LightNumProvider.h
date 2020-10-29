#pragma once
#include <GL\glut.h>

int currentLamp = 0;

GLenum getLamp() {
	auto lamp = currentLamp;
	switch (currentLamp++) {
		case 0: return GL_LIGHT0;
		case 1: return GL_LIGHT1;
		case 2: return GL_LIGHT2;
		case 3: return GL_LIGHT3;
		case 4: return GL_LIGHT4;
		case 5: return GL_LIGHT5;
		case 6: return GL_LIGHT6;
		case 7: return GL_LIGHT7;
		default:
			return -1;
			break;
	}
	return lamp;
}

