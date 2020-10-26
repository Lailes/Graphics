﻿#include <GL\glut.h>
#include <Windows.h>
#include <iostream>
#include <vector>

#include "Entities.h"

#define SPEED 3
#define MOVE_SPEED 0.05

#define ON true
#define OFF false

std::vector<SceneObject*> renderList;

int rot_x = 0;
int rot_y = 0;

void renderObjects() {
    for (const auto obj : renderList) {
        obj->draw();
    }
}

void clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glRotatef(rot_x, 1.0, 0.0, 0.0);
    glRotatef(rot_y, 0.0, 1.0, 0.0);
}

void apply() { glFlush(); glutSwapBuffers();}

void render() {
    clear();         

    renderObjects();
    
    apply();
}

void inputSpecial(int k, int x, int y) {
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
        case GLUT_KEY_F2: {
            for (const auto obj : renderList) {
                obj->restoreDefaults();
            }
            break;
        }
        default:
            break;
    }

    glutPostRedisplay();
}

void reshape(int width, int height){
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.2, 1.2, -1.2, 1.2, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void inputKeyboard(unsigned char key, int x, int y) {
    for (const auto obj : renderList) {
        obj->processInput(key, x, y);
    }
    glutPostRedisplay();
}

void initialize(int argc, char* argv[], int width, int height, const char* title) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow(title);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LIGHTING);
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glEnable(GL_NORMALIZE);

    glutDisplayFunc(render);
    glutSpecialFunc(inputSpecial);
    glutKeyboardFunc(inputKeyboard);
    glutReshapeFunc(reshape);
}


int main(int argc, char* argv[]) {
    

    renderList.push_back(new Cube(-0.8, 0.0, 0.0, 0.1));
    renderList.push_back(new Cube(0.8, 0.0, 0.0, 0.1));
    renderList.push_back(new Cube(0.0, 0.8, 0.0, 0.1));
    renderList.push_back(new Cube(0.0,- 0.8, 0.0, 0.1));
    renderList.push_back(new Cube(0.0, 0.0, 0.8, 0.1));
    renderList.push_back(new Cube(00.0, 0.0, -0.8, 0.1));

    auto light0 = new DotLight(0.5, 0.5, 0, 0.92, 0.79, 1.0, GL_LIGHT0, true, 0.02);
    light0->setProcessFunc([](unsigned char& key, int& x, int& y, SceneObject* object) {
        if (key == '1') {
            Light* l = (Light*)object;
            l->turn(!l->isOn());
            std::cout << "[LOG] Light0: " << (l->isOn() ? "ON" : "OFF") << std::endl;
        }
        
    });
    
    light0->setRestoreFunc([](SceneObject* object) {
        Light* l = (Light*)object;
        l->turn(OFF);
        std::cout << "[LOG] Light0: " << (l->isOn() ? "ON" : "OFF") << std::endl;
        });

    light0->turnDecay(ON);
    renderList.push_back(light0);

    auto moveCube = new Cube(0.0, 0.0, 0.0, 0.15);
    renderList.push_back(moveCube);

    moveCube->setProcessFunc([](unsigned char& key, int& x, int& y, SceneObject* object) {
        if (key == 'w') { object->changeY(MOVE_SPEED); }
        if (key == 's') { object->changeY(-MOVE_SPEED); }
        if (key == 'a') { object->changeX(-MOVE_SPEED); }
        if (key == 'd') { object->changeX(MOVE_SPEED); }
        if (key == 'r') { object->changeZ(MOVE_SPEED); }
        if (key == 'f') { object->changeZ(-MOVE_SPEED); }
    });

    moveCube->setRestoreFunc([](SceneObject* object) {
        object->setDefaultPosition();
    });
    

    initialize(argc, argv, 1000, 1000, "Super AAA 3D Game GOTY Legendary Edition");

    glutMainLoop();

    return 0;
}