#pragma once

#include<glut.h>
#include<vector>
#include<string>

#include "SceneObject.h"

#define SPEED 3

using namespace std;
using namespace SceneObjests;

class SceneOperator {
private:
	vector<SceneObject*> sceneObjects;
	int rot_x = 0;
	int rot_y = 0;
	int h, w;
	const char* t;
public:
	SceneOperator(int height, int weight, const char* title) : h(height), w(weight), t(title) {}
	void initialize(int argc, char* argv[]);
	int start();
	void render();
	void input(int k, int x, int y);
	void addObject(SceneObject* sceneobject);
	~SceneOperator();
};

