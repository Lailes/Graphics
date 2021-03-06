#include <GL\glut.h>
#include "Ball.h"

void Ball::draw() {
	if (!display) return;
	applyMaterial();
	glPushMatrix();
	glTranslatef(x, y, z);
	glutSolidSphere(radius, 100, 100);
	glPopMatrix();
	removeMaterial();
}
