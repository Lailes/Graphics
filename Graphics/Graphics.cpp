#include <GL\glut.h>
#include <Windows.h>
#include <iostream>
#include <vector>

#include "Entities.h"

#include "Materials.h"

#define SPEED 3
#define MOVE_SPEED 0.05

#define LIGHT 0.05

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
    glOrtho(-1.5, 1.5, -1.5, 1.5, -1.5, 1.5);
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

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, 1.0);
    glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, 1.0);
    GLfloat amb[] = { LIGHT, LIGHT, LIGHT, 1.0 };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);
    glEnable(GL_NORMALIZE);

    glutDisplayFunc(render);
    glutSpecialFunc(inputSpecial);
    glutKeyboardFunc(inputKeyboard);
    glutReshapeFunc(reshape);
}


int main(int argc, char* argv[]) {
    initMaterials();
    
    auto cube = new Cube(-0.8, 0.0, 0.0, 0.1);
    cube->setMaterial(greenRubber);
    renderList.push_back(cube);
    auto cube2 = new Cube(0.8, 0.0, 0.0, 0.1);
    cube2->setMaterial(pearl);
    renderList.push_back(cube2);
    auto cube3 = new Cube(0.0, 0.8, 0.0, 0.1);
    cube3->setMaterial(emerald);
    renderList.push_back(cube3);
    auto cube4 = new Cube(0.0, -0.8, 0.0, 0.1);
    cube4->setMaterial(bronze);
    renderList.push_back(cube4);
    auto cube6 = new Cube(0.0, 0.0, 0.8, 0.1);
    cube6->setMaterial(chrome);
    renderList.push_back(cube6);
    auto cube5 = new Cube(0.0, 0.0, -0.8, 0.1);
    cube5->setMaterial(obsidian);
    renderList.push_back(cube5);

    auto light0 = new DotLight(0.5, 0.5, 0.5, GL_LIGHT0);
    light0->setColor(0.92, 0.79, 1.0);
    light0->setProcessFunc([](unsigned char& key, int& x, int& y, SceneObject* object) {
        if (key == '1') {Light* l = (Light*)object; l->turn(!l->isOn());}  
    });
    
    light0->turnDecay(ON);
    renderList.push_back(light0);


    auto lightProjector = new ProjectorLight(-0.6, -0.6, -0.6, GL_LIGHT1);
    lightProjector->setDirection(1.0,1.0, 1.0);
    lightProjector->setExponent(200);
    lightProjector->setAngle(20);
    lightProjector->setColor(0.88, 0.63, 1.0);
    lightProjector->setProcessFunc([](unsigned char& key, int& x, int& y, SceneObject* object) {
        if (key == '2') { Light* l = (Light*)object; l->turn(!l->isOn());}
     });

    renderList.push_back(lightProjector);

    auto vectorLight = new VectorLight(1.0,1.0,1.0, GL_LIGHT2);
    vectorLight->setColor(0.88, 0.40, 0.74);
    vectorLight->setProcessFunc([](unsigned char& key, int& x, int& y, SceneObject* object) {
        if (key == '3') { Light* l = (Light*)object; l->turn(!l->isOn()); }
        });
    renderList.push_back(vectorLight);

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

    moveCube->setMaterial(obsidian);

    auto pane2 = new Pane(0.62, 0.72, 1.0);
    pane2->addVertex(0.7, 0.0, 0.0);
    pane2->addVertex(0.0, 0.7, 0.0);
    pane2->addVertex(0.0, 0.0, 0.7);
    pane2->setMaterial(obsidian);
    pane2->setProcessFunc([](unsigned char& key, int& x, int& y, SceneObject* object) {
        if (key == ']') { object->visibilty(!object->isVisible()); }
        });

    pane2->setRestoreFunc([](SceneObject* object) {
        object->visibilty(true);
        });

    renderList.push_back(pane2);
    
    auto ball = new Ball(0.2);
    ball->setMaterial(greenRubber);
    renderList.push_back(ball);

    initialize(argc, argv, 1000, 1000, "Super AAA 3D Game GOTY Legendary Edition");

    glutMainLoop();

    deleteMaterials();


    return 0;
}