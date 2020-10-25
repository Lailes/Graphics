#include <glut.h>
#include <Windows.h>

#include "SceneOperator.h"
#include "Entities.h"

using namespace SceneObjests;


SceneOperator* scene;

void render() {
    scene->render();
}

void input(int k, int x, int y) {
    scene->input(k, x, y);
}

int main(int argc, char* argv[]) {
    
    auto cube1 = new Cube(-0.5, -0.5, -0.5, 0.1);
    auto cube2 = new Cube(-0.5, 0.5, -0.5, 0.1);
    auto cube3 = new Cube(0.5, -0.5, -0.5, 0.1);
    auto cube4 = new Cube(0.5, 0.5, -0.5, 0.1);
    auto cube5 = new Cube(-0.5, -0.5, 0.5, 0.1);
    auto cube6 = new Cube(-0.5, 0.5, 0.5, 0.1);
    auto cube7 = new Cube(0.5, -0.5, 0.5, 0.1);
    auto cube8 = new Cube(0.5, 0.5, 0.5, 0.1);
    auto cube9 = new Cube(0.0, 0.0, 0.0, 0.1);

    scene = new SceneOperator(800, 800, "Amadera");
    scene->initialize(argc, argv);

    glutDisplayFunc(render);
    glutSpecialFunc(input);

    scene->addObject(cube1);
    scene->addObject(cube2);
    scene->addObject(cube3);
    scene->addObject(cube4);
    scene->addObject(cube5);
    scene->addObject(cube6);
    scene->addObject(cube7);
    scene->addObject(cube8);
    scene->addObject(cube9);


    scene->start();
   
    delete scene;
    return 0;
}