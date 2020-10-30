#pragma once
#include <GL\glut.h>
#include <iostream>
#include "SceneObject.h"
#include <vector>
#include "Material.h"


class Shape : public SceneObject {

protected:
	Material* shapeMaterial;
	Material* defaultMaterial;

public:
	Shape(float x, float y, float z): SceneObject(x,y,z){

		Material* material = new Material();
		material->rgb = new float[] {1.0, 1.0, 1.0, 1.0};
		material->ambientRGB = new float[] {0.2, 0.2, 0.2, 1.0};
		material->diffuseRGB = new float[] {0.8, 0.8, 0.8, 1.0};
		material->specularRGB = new float[] {0.0, 0.0, 0.0, 1.0};
		material->shiness = 0;
		material->emission = 0;

		defaultMaterial = material;
		shapeMaterial = new Material(*material);
	}

	void setColor(float r, float g, float b) {
		this->shapeMaterial->rgb[0] = r;
		this->shapeMaterial->rgb[1] = g;
		this->shapeMaterial->rgb[2] = b;
	}

	void setMaterial(Material* material) {
		this->shapeMaterial = material;
	}

protected:
	void applyMaterial() {
			glColor3f(shapeMaterial->rgb[0], shapeMaterial->rgb[1], shapeMaterial->rgb[2]);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, shapeMaterial->diffuseRGB);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &shapeMaterial->shiness);
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, shapeMaterial->ambientRGB);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, shapeMaterial->specularRGB);
			glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
			glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT);
			glColorMaterial(GL_FRONT_AND_BACK, GL_SPECULAR);
			glColorMaterial(GL_FRONT_AND_BACK, GL_SHININESS);
		
	}

	void removeMaterial() {
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, defaultMaterial->diffuseRGB);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &defaultMaterial->shiness);
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, defaultMaterial->ambientRGB);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, defaultMaterial->specularRGB);
			glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
			glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT);
			glColorMaterial(GL_FRONT_AND_BACK, GL_SPECULAR);
			glColorMaterial(GL_FRONT_AND_BACK, GL_SHININESS);
		
	}

public:
	~Shape() {
		delete defaultMaterial;
		delete shapeMaterial;
	}
};

