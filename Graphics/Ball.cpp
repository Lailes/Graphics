#include <GL\glut.h>
#include "Ball.h"

void Ball::draw() {
	if (!display) return;
	glutSolidSphere(radius, 50, 40);
}
