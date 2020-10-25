#include "Cube.h"
#include <glut.h>

void Cube::draw() {
    glBegin(GL_POLYGON);
    glColor3f(1.0, edgeSize, .0);
    glVertex3f(edgeSize + x, -edgeSize + y, -edgeSize + z);
    glVertex3f(edgeSize + x, edgeSize + y, -edgeSize + z);
    glVertex3f(-edgeSize + x, edgeSize + y, -edgeSize + z);
    glVertex3f(-edgeSize + x, -edgeSize + y, -edgeSize + z);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.7, .7, .7);
    glVertex3f(edgeSize + x, -edgeSize + y, edgeSize + z);
    glVertex3f(edgeSize + x, edgeSize + y, edgeSize + z);
    glVertex3f(-edgeSize + x, edgeSize + y, edgeSize + z);
    glVertex3f(-edgeSize + x, -edgeSize + y, edgeSize + z);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.2, .7, .8);
    glVertex3f(edgeSize + x, -edgeSize + y, -edgeSize + z);
    glVertex3f(edgeSize + x, edgeSize + y, -edgeSize + z);
    glVertex3f(edgeSize + x, edgeSize + y, edgeSize + z);
    glVertex3f(edgeSize + x, -edgeSize + y, edgeSize + z);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.0, 1., .0);
    glVertex3f(-edgeSize + x, -edgeSize + y, edgeSize + z);
    glVertex3f(-edgeSize + x , edgeSize + y, edgeSize + z);
    glVertex3f(-edgeSize + x, edgeSize + y, -edgeSize + z);
    glVertex3f(-edgeSize + x, -edgeSize + y, -edgeSize + z);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(edgeSize + x, edgeSize + y, edgeSize + z);
    glVertex3f(edgeSize + x, edgeSize + y, -edgeSize + z);
    glVertex3f(-edgeSize + x, edgeSize + y, -edgeSize + z);
    glVertex3f(-edgeSize + x, edgeSize + y, edgeSize + z);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(edgeSize + x, -edgeSize + y, -edgeSize + z);
    glVertex3f(edgeSize + x, -edgeSize + y, edgeSize + z);
    glVertex3f(-edgeSize + x, -edgeSize + y, edgeSize + z);
    glVertex3f(-edgeSize + x, -edgeSize + y, -edgeSize + z);
    glEnd();
}

void Cube::setEdgeSize(float size) {
    this->edgeSize = size;
}
