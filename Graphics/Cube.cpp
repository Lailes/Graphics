#include "Cube.h"
#include <GL\glut.h>

void Cube::draw() {
    if (!display) return;

    applyMaterial();

    glPushMatrix();
    glTranslatef(x, y, z);
    glutSolidCube(edgeSize);
    glPopMatrix();

    removeMaterial();
}