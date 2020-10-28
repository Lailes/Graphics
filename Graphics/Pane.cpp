#include <GL\glut.h>
#include "Pane.h"

void Pane::addVertex(float x, float y, float z) {
	dots.push_back(new Dot(x, y, z));
}

void Pane::draw() {
	if (!display)return;

	glBegin(GL_POLYGON);
	glColor3f(r, g, b);
	for (const Dot* dot : dots) glVertex3f(dot->xf, dot->yf, dot->zf);
	glEnd();
}

Pane::~Pane() {
	for (const Dot* dot : dots) {
		delete dot;
	}
}
