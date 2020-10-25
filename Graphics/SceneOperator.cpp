#include "SceneOperator.h"

void SceneOperator::initialize(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(w, h);
	glutCreateWindow(t);
	glEnable(GL_DEPTH_TEST);
}

int SceneOperator::start() {
	glutMainLoop();
	return 0;
}

void SceneOperator::render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glRotatef(rot_x, 1.0, 0.0, 0.0);
	glRotatef(rot_y, 0.0, 1.0, 0.0);

	for (const auto object : sceneObjects) {
		object->draw();
	}

	glFlush();
	glutSwapBuffers();
}

void SceneOperator::input(int k, int x, int y) {
	switch (k) {
		case GLUT_KEY_UP:
			rot_x += SPEED;
			break;
		case GLUT_KEY_DOWN:
			rot_x -= SPEED;
			break;
		case GLUT_KEY_LEFT:
			rot_y -= SPEED;
			break;
		case GLUT_KEY_RIGHT:
			rot_y += SPEED;
			break;
		case GLUT_KEY_F1:
			exit(0);
			break;
		default:
			break;
	}

	glutPostRedisplay();
}

void SceneOperator::addObject(SceneObject* sceneObject) {
	sceneObjects.push_back(sceneObject);
}

SceneOperator::~SceneOperator() {
	for (const auto obj : sceneObjects) {
		delete obj;
	}
}
