#include "Cube.h"
#include <GL\glut.h>

void Cube::draw() {
    if (!display) return;

    applyMaterial();

    glBegin(GL_POLYGON);
    glVertex3f(edgeSize + x, -edgeSize + y, -edgeSize + z);
    glVertex3f(edgeSize + x, edgeSize + y, -edgeSize + z);
    glVertex3f(-edgeSize + x, edgeSize + y, -edgeSize + z);
    glVertex3f(-edgeSize + x, -edgeSize + y, -edgeSize + z);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(edgeSize + x, -edgeSize + y, edgeSize + z);
    glVertex3f(edgeSize + x, edgeSize + y, edgeSize + z);
    glVertex3f(-edgeSize + x, edgeSize + y, edgeSize + z);
    glVertex3f(-edgeSize + x, -edgeSize + y, edgeSize + z);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(edgeSize + x, -edgeSize + y, -edgeSize + z);
    glVertex3f(edgeSize + x, edgeSize + y, -edgeSize + z);
    glVertex3f(edgeSize + x, edgeSize + y, edgeSize + z);
    glVertex3f(edgeSize + x, -edgeSize + y, edgeSize + z);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-edgeSize + x, -edgeSize + y, edgeSize + z);
    glVertex3f(-edgeSize + x , edgeSize + y, edgeSize + z);
    glVertex3f(-edgeSize + x, edgeSize + y, -edgeSize + z);
    glVertex3f(-edgeSize + x, -edgeSize + y, -edgeSize + z);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(edgeSize + x, edgeSize + y, edgeSize + z);
    glVertex3f(edgeSize + x, edgeSize + y, -edgeSize + z);
    glVertex3f(-edgeSize + x, edgeSize + y, -edgeSize + z);
    glVertex3f(-edgeSize + x, edgeSize + y, edgeSize + z);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(edgeSize + x, -edgeSize + y, -edgeSize + z);
    glVertex3f(edgeSize + x, -edgeSize + y, edgeSize + z);
    glVertex3f(-edgeSize + x, -edgeSize + y, edgeSize + z);
    glVertex3f(-edgeSize + x, -edgeSize + y, -edgeSize + z);
    glEnd();

    removeMaterial();
}