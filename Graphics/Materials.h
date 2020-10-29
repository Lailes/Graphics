#pragma once
#include "Material.h"

Material* emerald;
Material* bronze;
Material* chrome;
Material* greenRubber;
Material* gold;
Material* pearl;
Material* obsidian;



void initMaterials() {
	emerald = new Material();
	emerald->ambientRGB = new float[] {0.0215, 0.01745, 0.0215};
	emerald->diffuseRGB = new float[] {0.07568, 0.61424, 0.07568};
	emerald->specularRGB = new float[] {0.633, 0.727811, 0.633};
	emerald->shiness = 0.6;
	emerald->rgb = new float[] {0.0, 0.64, 0.04};

	bronze = new Material();
	bronze->ambientRGB = new float[] {0.2125, 0.1275, 0.054};
	bronze->diffuseRGB = new float[] {0.714, 0.4284, 0.18144};
	bronze->specularRGB = new float[] {0.393548, 0.271906, 0.166721};
	bronze->shiness = 0.2;
	bronze->rgb = new float[] {0.82, 0.51, 0.24};

	chrome = new Material();
	chrome->ambientRGB = new float[] {0.25, 0.25, 0.25};
	chrome->diffuseRGB = new float[] {0.4, 0.4, 0.4};
	chrome->specularRGB = new float[] {0.774597, 0.774597, 0.774597};
	chrome->shiness = 0.6;
	chrome->rgb = new float[] {0.88, 0.88, 0.88};

	greenRubber = new Material();
	greenRubber->ambientRGB = new float[] {0.0, 0.05, 0.0};
	greenRubber->diffuseRGB = new float[] {0.4, 0.5, 0.4};
	greenRubber->specularRGB = new float[] {0.04, 0.07, 0.04};
	greenRubber->shiness = 0.078125;
	greenRubber->rgb = new float[] {0.0, 1.0, 0.0};

	gold = new Material();
	gold->ambientRGB = new float[] {0.24725, 0.1995,0.0745};
	gold->diffuseRGB = new float[] {0.75164, 0.60648, 0.22648};
	gold->specularRGB = new float[] {0.628281, 0.555802, 0.366065};
	gold->shiness = 0.4;
	gold->rgb = new float[] {1.0, 0.85, 0.24};

	pearl = new Material();
	pearl->ambientRGB = new float[] {0.25, 0.20725, 0.20725};
	pearl->diffuseRGB = new float[] {1.0, 0.829, 0.829};
	pearl->specularRGB = new float[] {0.296648,	0.296648, 0.296648};
	pearl->shiness = 0.088;
	pearl->rgb = new float[] {0.91, 0.91, 0.82};

	obsidian = new Material();
	obsidian->ambientRGB = new float[] {0.05375, 0.05, 0.06625};
	obsidian->diffuseRGB = new float[] {0.18275, 0.17, 0.22525};
	obsidian->specularRGB = new float[] {0.332741, 0.328634, 0.346435};
	obsidian->shiness = 0.3;
	obsidian->rgb = new float[] {0.06, 0.02, 0.1};
}


void deleteMaterials() {
	delete emerald;
	delete bronze;
	delete chrome;
	delete greenRubber;
	delete gold;
	delete pearl;
	delete obsidian;
}