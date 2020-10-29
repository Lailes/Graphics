#include <GL\glut.h>
#include "Ball.h"

void Ball::draw() {
	if (!display) return;
	applyMaterial();
	glutSolidSphere(radius, 50, 40);
	removeMaterial();
}
