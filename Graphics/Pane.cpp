#include <GL\glut.h>
#include "Pane.h"

void Pane::addVertex(float x, float y, float z) {
	dots.push_back(new Dot(x, y, z));
}

void Pane::draw() {
	if (!display)return;
	applyMaterial();
	glBegin(GL_POLYGON);
	for (const Dot* dot : dots) glVertex3f(dot->xf, dot->yf, dot->zf);
	glEnd();
	removeMaterial();
}

Pane::~Pane() {
	for (const Dot* dot : dots) {
		delete dot;
	}
}
