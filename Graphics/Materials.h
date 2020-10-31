#pragma once
#include "Material.h"

Material* emerald;
Material* bronze;
Material* chrome;
Material* greenRubber;
Material* gold;
Material* pearl;
Material* obsidian;
Material* mirror;
Material* redRubber;
Material* redGlass;
Material* greyGlass;

int currentLight = 0;

Material* getNextMaterial() {
	switch (currentLight++) {
		case 0: return emerald;
		case 1: return bronze;
		case 2: return chrome;
		case 3: return greenRubber;
		case 4: return gold;
		case 5: return pearl;
		case 6: return obsidian;
		case 7: return mirror;
		case 8: return redRubber;
		case 9: return redGlass;
		default:
			currentLight = 1;
			break;
	}
	return emerald;
}

void initMaterials() {
	emerald = new Material();

#ifdef _DEBUG
	emerald->name = "Emerland";
#endif
	emerald->ambientRGB = new float[] {0.0215, 0.01745, 0.0215,1.0};
	emerald->diffuseRGB = new float[] {0.07568, 0.61424, 0.07568, 1.0};
	emerald->specularRGB = new float[] {0.633, 0.727811, 0.633, 1.0};
	emerald->shiness = 0.6;
	emerald->rgb = new float[] {0.0, 0.64, 0.04, 1.0};

	bronze = new Material();
#ifdef _DEBUG
	bronze->name = "Bronze";
#endif
	bronze->ambientRGB = new float[] {0.2125, 0.1275, 0.054, 1.0};
	bronze->diffuseRGB = new float[] {0.714, 0.4284, 0.18144, 1.0};
	bronze->specularRGB = new float[] {0.393548, 0.271906, 0.166721, 1.0};
	bronze->shiness = 0.2;
	bronze->rgb = new float[] {0.82, 0.51, 0.24, 1.0};

	chrome = new Material();
#ifdef _DEBUG
	chrome->name = "chrome";
#endif
	chrome->ambientRGB = new float[] {0.25, 0.25, 0.25, 1.0};
	chrome->diffuseRGB = new float[] {0.4, 0.4, 0.4, 1.0};
	chrome->specularRGB = new float[] {0.774597, 0.774597, 0.774597, 1.0};
	chrome->shiness = 0.6;
	chrome->rgb = new float[] {0.88, 0.88, 0.88, 1.0};

	greenRubber = new Material();
#ifdef _DEBUG
	greenRubber->name = "Green rubber";
#endif
	greenRubber->ambientRGB = new float[] {0.0, 0.05, 0.0, 1.0};
	greenRubber->diffuseRGB = new float[] {0.4, 0.5, 0.4, 1.0};
	greenRubber->specularRGB = new float[] {0.04, 0.07, 0.04, 1.0};
	greenRubber->shiness = 0.078125;
	greenRubber->rgb = new float[] {0.0, 1.0, 0.0, 1.0};

	gold = new Material();
#ifdef _DEBUG
	gold->name = "Gold";
#endif
	gold->ambientRGB = new float[] {0.24725, 0.1995,0.0745,1.0};
	gold->diffuseRGB = new float[] {0.75164, 0.60648, 0.22648, 1.0};
	gold->specularRGB = new float[] {0.628281, 0.555802, 0.366065, 1.0};
	gold->shiness = 0.4;
	gold->rgb = new float[] {1.0, 0.85, 0.24, 1.0};

	pearl = new Material();
#ifdef _DEBUG
	pearl->name = "Pearl";
#endif
	pearl->ambientRGB = new float[] {0.25, 0.20725, 0.20725, 1.0};
	pearl->diffuseRGB = new float[] {1.0, 0.829, 0.829, 1.0};
	pearl->specularRGB = new float[] {0.296648,	0.296648, 0.296648, 1.0};
	pearl->shiness = 0.088;
	pearl->rgb = new float[] {0.91, 0.91, 0.82, 1.0};

	obsidian = new Material();
#ifdef _DEBUG
	obsidian->name = "Obsidian";
#endif
	obsidian->ambientRGB = new float[] {0.05375, 0.05, 0.06625, 1.0};
	obsidian->diffuseRGB = new float[] {0.18275, 0.17, 0.22525, 1.0};
	obsidian->specularRGB = new float[] {0.332741, 0.328634, 0.346435, 1.0};
	obsidian->shiness = 0.3;
	obsidian->rgb = new float[] {0.06, 0.02, 0.1, 1.0};

	mirror = new Material();
#ifdef _DEBUG
	mirror->name = "Mirror";
#endif
	mirror->ambientRGB = new float[] {0.0, 0.0, 0.0, 1.0};
	mirror->diffuseRGB = new float[] {0.0, 0.0, 0.0, 1.0};
	mirror->specularRGB = new float[] {1.0, 1.0, 1.0, 1.0};
	mirror->shiness = 128.0;
	mirror->rgb = new float[] {1.0, 1.0, 1.0, 1.0};

	redRubber = new Material();
#ifdef _DEBUG
	redRubber->name = "Red rubber";
#endif
	redRubber->ambientRGB = new float[] {0.5, 0.0, 0.0,1.0};
	redRubber->diffuseRGB = new float[] {0.5, 0.0, 1.0,1.0};
	redRubber->specularRGB = new float[] {1.0, 1.0, 1.0,1.0};
	redRubber->shiness = 0.5f * 128;
	redRubber->rgb = new float[] {1.0, 0.0, 0.0,1.0};


	redGlass = new Material();
#ifdef _DEBUG
	redGlass->name = "Light blue glass";
#endif
	redGlass->ambientRGB = new float[] {0.5, 0.0, 0.0, 1.0};
	redGlass->diffuseRGB = new float[] {0.2, 0.0, 1.0, 1.0};
	redGlass->specularRGB = new float[] {1.0, 1.0, 1.0, 1.0};
	redGlass->shiness = 0.5f * 128;
	redGlass->rgb = new float[] {0.4, 0.6, 0.6, 0.7};


	greyGlass = new Material();
#ifdef _DEBUG
	greyGlass->name = "Light gray glass";
#endif
	greyGlass->ambientRGB = new float[] {0.2, 0.2, 0.2, 1.0};
	greyGlass->diffuseRGB = new float[] {0.2, 0.2, 0.2, 1.0};
	greyGlass->specularRGB = new float[] {0.2, 0.2, 0.2, 1.0};
	greyGlass->shiness = 0.5f * 128;
	greyGlass->rgb = new float[] {0.8, 0.8, 0.8, 0.8};


}


void deleteMaterials() {
	delete emerald;
	delete bronze;
	delete chrome;
	delete greenRubber;
	delete gold;
	delete pearl;
	delete obsidian;
	delete mirror;
	delete redRubber;
	delete redGlass;
	delete greyGlass;
}
