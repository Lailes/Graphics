#include <GL\glut.h>
#include <Windows.h>
#include <iostream>
#include <vector>

#include "Entities.h"
#include "LightCharacteristics.h"
#include "LightNumProvider.h"
#include "Materials.h"

#define SPEED 3
#define MOVE_SPEED 0.05

#define LIGHT 0.05

#define ON true
#define OFF false

std::vector<Shape*> renderList;

std::vector<Light*> lights;

int rot_x = 0;
int rot_y = 0;

void render() {        

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();



    for (const auto light : lights) {
        light->draw();
    }

    glRotatef(rot_x, 1.0, 0.0, 0.0);
    glRotatef(rot_y, 0.0, 1.0, 0.0);

    for (const auto obj : renderList) {
        obj->draw();
    }

    glFlush();
    glutSwapBuffers();
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
    for (const auto obj : lights) {
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
    initLightCharacteristics();
   
    //////////////////////     SHAPES     ///////////////////////////

    auto cube = new Cube(-0.8, 0.0, 0.0, 0.2);
    cube->setMaterial(greenRubber);
    renderList.push_back(cube);
    auto cube2 = new Cube(0.8, 0.0, 0.0, 0.2);
    cube2->setMaterial(pearl);
    renderList.push_back(cube2);
    auto cube3 = new Cube(0.0, 0.8, 0.0, 0.2);
    cube3->setMaterial(emerald);
    renderList.push_back(cube3);
    auto cube4 = new Cube(0.0, -0.8, 0.0, 0.2);
    cube4->setMaterial(bronze);
    renderList.push_back(cube4);
    auto cube6 = new Cube(0.0, 0.0, 0.8, 0.2);
    cube6->setMaterial(chrome);
    renderList.push_back(cube6);
    auto cube5 = new Cube(0.0, 0.0, -0.8, 0.2);
    cube5->setMaterial(obsidian);
    renderList.push_back(cube5);

    auto moveCube = new Cube(-0.5, 0.0, 0.0, 0.2);
    moveCube->setName("Move cube");
    renderList.push_back(moveCube);

    moveCube->setProcessFunc([](unsigned char& key, int& x, int& y, SceneObject* object) {
        if (key == 'w') { object->changeY(MOVE_SPEED); }
        if (key == 's') { object->changeY(-MOVE_SPEED); }
        if (key == 'a') { object->changeX(-MOVE_SPEED); }
        if (key == 'd') { object->changeX(MOVE_SPEED); }
        if (key == 'r') { object->changeZ(MOVE_SPEED); }
        if (key == 'f') { object->changeZ(-MOVE_SPEED); }
        if (key == 'c') { object->visibilty(!object->isVisible()); }
        if (key == 'v') { 
#ifdef _DEBUG
            auto material = getNextMaterial();
            std::cout << "Swithching " << object->getName() << " material: \"" << material->name << "\"" << std::endl;
#endif
            ((Shape*)object)->setMaterial(material);
        }
        });

    moveCube->setRestoreFunc([](SceneObject* object) {
        object->setDefaultPosition();
        });

    moveCube->setMaterial(greenRubber);

    auto ball = new Ball(0.2);
    ball->setName("Ball");
    ball->setMaterial(redRubber);
    ball->setProcessFunc([](unsigned char& key, int& x, int& y, SceneObject* object) {
        if (key == 'y') { object->changeY(MOVE_SPEED); }
        if (key == 'h') { object->changeY(-MOVE_SPEED); }
        if (key == 'g') { object->changeX(-MOVE_SPEED); }
        if (key == 'j') { object->changeX(MOVE_SPEED); }
        if (key == 'i') { object->changeZ(MOVE_SPEED); }
        if (key == 'k') { object->changeZ(-MOVE_SPEED); }
        if (key == 'b') { object->visibilty(!object->isVisible()); }
        if (key == 'n') { 
#ifdef _DEBUG
            auto material = getNextMaterial();
            std::cout << "Swithching " << object->getName() << " material: \"" << material->name << "\"" << std::endl;
#endif
            ((Shape*)object)->setMaterial(material);
        }

        });
    renderList.push_back(ball);

    //////////////////////     SHAPES     ///////////////////////////


    //////////////////////     LIGHTS     ///////////////////////////

    auto light0 = new DotLight(0.8, 0.4, 0.6, getLamp());
    light0->setLigthCharacteristic(dotted);
    light0->setName("Dot light");
    light0->setProcessFunc([](unsigned char& key, int& x, int& y, SceneObject* object) {
        if (key == '1') {
            Light* l = (Light*)object; 
            l->turn(!l->isOn());
        } 
        if (key == 'p') { object->changeY(MOVE_SPEED); }
        if (key == ';') { object->changeY(-MOVE_SPEED); }
        if (key == 'l') { object->changeX(-MOVE_SPEED); }
        if (key == '\'') { object->changeX(MOVE_SPEED); }
        if (key == '[') { object->changeZ(MOVE_SPEED); }
        if (key == ']') { object->changeZ(-MOVE_SPEED); }
        if (key == '4') {
#ifdef _DEBUG
            auto light = getNextLight();
            std::cout << "Swithching " << object->getName() << " light: \"" << light->name << "\"" << std::endl;
#endif
            ((Light*)object)->setLigthCharacteristic(light);
        }
    });
    
    light0->turnDecay(OFF);
    lights.push_back(light0);


    auto lightProjector = new ProjectorLight(1.0, 1.0, 1.0, getLamp());
    lightProjector->setName("Projector light");
    lightProjector->setDirection(-1.0, -1.0, -1.0);
    lightProjector->setExponent(15.0);
    lightProjector->setAngle(30);
    lightProjector->setProcessFunc([](unsigned char& key, int& x, int& y, SceneObject* object) {
        if (key == '2') { 
            Light* l = (Light*)object; 
            l->turn(!l->isOn());
        }
        if (key == '5') {
#ifdef _DEBUG
            auto light = getNextLight();
            std::cout << "Swithching " << object->getName() << " light: \"" << light->name << "\"" << std::endl;
#endif
            ((Light*)object)->setLigthCharacteristic(light);
        }

     });

    lights.push_back(lightProjector);

    auto vectorLight = new VectorLight(1.0,1.0,1.0, getLamp());
    vectorLight->setName("Vector light");
    vectorLight->setProcessFunc([](unsigned char& key, int& x, int& y, SceneObject* object) {
        if (key == '3') { 
            Light* l = (Light*)object;
            l->turn(!l->isOn());
        }
        if (key == '6') {
#ifdef _DEBUG
            auto light = getNextLight();
            std::cout << "Swithching " << object->getName() << " light: \"" << light->name << "\"" << std::endl;
#endif
            ((Light*)object)->setLigthCharacteristic(light);
        }

        });
    lights.push_back(vectorLight);
    

    //////////////////////     LIGHTS     ///////////////////////////


    initialize(argc, argv, 1000, 1000, "Super AAA 3D Game GOTY Legendary Edition (11/10 - IGN)");

    glutMainLoop();

    deleteMaterials();
    deleteLightCharacteristics();

    return 0;
}