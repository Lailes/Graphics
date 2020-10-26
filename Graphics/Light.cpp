#include "Light.h"

Light::Light(float x, float y, float z, float r, float g, float b, GLenum lamp, bool drawMark, float markSize) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->r = r;
	this->g = g;
	this->b = b;
	this->lamp = lamp;
	this->drawMark = drawMark;
	this->markSize = markSize;
}

void Light::draw() {
	if (!drawMark) return;
	
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.5, 0.0);
	glVertex3f(markSize + x, 0.0 + y, markSize + z);
	glVertex3f(-markSize + x, 0.0 + y, markSize + z);
	glVertex3f(0.0 + x, markSize + y, 0.0 + z);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(markSize + x, 0.0 + y, -markSize + z);
	glVertex3f(-markSize + x, 0.0 + y, -markSize + z);
	glVertex3f(0.0 + x, markSize + y, 0.0 + z);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.4, 0.8);
	glVertex3f(markSize + x, 0.0 + y, markSize + z);
	glVertex3f(markSize + x, 0.0 + y, -markSize + z);
	glVertex3f(0.0 + x, markSize + y, 0.0 + z);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.1, 0.6);
	glVertex3f(-markSize + x, 0.0 + y, markSize + z);
	glVertex3f(-markSize + x, 0.0 + y, -markSize + z);
	glVertex3f(0.0 + x, markSize + y, 0.0 + z);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(markSize + x, 0.0 + y, markSize + z);
	glVertex3f(-markSize + x, 0.0 + y, markSize + z);
	glVertex3f(0.0 + x, -markSize + y, 0.0 + z);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.6, 1.0);
	glVertex3f(markSize + x, 0.0 + y, -markSize + z);
	glVertex3f(-markSize + x, 0.0 + y, -markSize + z);
	glVertex3f(0.0 + x, -markSize + y, 0.0 + z);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 1.0, 0.8);
	glVertex3f(markSize + x, 0.0 + y, markSize + z);
	glVertex3f(markSize + x, 0.0 + y, -markSize + z);
	glVertex3f(0.0 + x, -markSize + y, 0.0 + z);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.8, 0.3);
	glVertex3f(-markSize + x, 0.0 + y, markSize + z);
	glVertex3f(-markSize + x, 0.0 + y, -markSize + z);
	glVertex3f(0.0 + x, -markSize + y, 0.0 + z);
	glEnd();


}
