#include <GL\glut.h>
#include "Ball.h"

void Ball::draw() {
	glutSolidSphere(radius, 50, 40);
}
