#include <GL\glut.h>
#include "Pyramid.h"

void Pyramid::draw() {
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.5, 0.0);
	glVertex3f(edgeSize + x, 0.0 + y, edgeSize + z);
	glVertex3f(-edgeSize + x, 0.0 + y, edgeSize + z);
	glVertex3f(0.0 + x, edgeSize + y, 0.0 + z);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(edgeSize + x, 0.0 + y, -edgeSize + z);
	glVertex3f(-edgeSize + x, 0.0 + y, -edgeSize + z);
	glVertex3f(0.0 + x, edgeSize + y, 0.0 + z);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.4, 0.8);
	glVertex3f(edgeSize + x, 0.0 + y, edgeSize + z);
	glVertex3f(edgeSize + x, 0.0 + y, -edgeSize + z);
	glVertex3f(0.0 + x, edgeSize + y, 0.0 + z);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.1, 0.6);
	glVertex3f(-edgeSize + x, 0.0 + y, edgeSize + z);
	glVertex3f(-edgeSize + x, 0.0 + y, -edgeSize + z);
	glVertex3f(0.0 + x, edgeSize + y, 0.0 + z);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(edgeSize + x, 0.0 + y, edgeSize + z);
	glVertex3f(-edgeSize + x, 0.0 + y, edgeSize + z);
	glVertex3f(0.0 + x, -edgeSize + y, 0.0 + z);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.6, 1.0);
	glVertex3f(edgeSize + x, 0.0 + y, -edgeSize + z);
	glVertex3f(-edgeSize + x, 0.0 + y, -edgeSize + z);
	glVertex3f(0.0 + x, -edgeSize + y, 0.0 + z);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 1.0, 0.8);
	glVertex3f(edgeSize + x, 0.0 + y, edgeSize + z);
	glVertex3f(edgeSize + x, 0.0 + y, -edgeSize + z);
	glVertex3f(0.0 + x, -edgeSize + y, 0.0 + z);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.8, 0.3);
	glVertex3f(-edgeSize + x, 0.0 + y, edgeSize + z);
	glVertex3f(-edgeSize + x, 0.0 + y, -edgeSize + z);
	glVertex3f(0.0 + x, -edgeSize + y, 0.0 + z);
	glEnd();
}
