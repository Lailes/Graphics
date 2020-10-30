#pragma 
#include "LightCharacteristic.h"


LightCharacteristic* bright;
LightCharacteristic* dotted;
LightCharacteristic* red;
LightCharacteristic* blue;
LightCharacteristic* green;

int current = 0;

LightCharacteristic* getNextLight() {

	switch (current++) {
		case 0: return bright;
		case 1: return dotted;
		case 2: return red;
		case 3: return blue;
		case 4: return green;
		default:
			current = 1;
			break;
	}
	return bright;
}

void initLightCharacteristics() {
	bright = new LightCharacteristic();
#ifdef _DEBUG
	bright->name = "Bright";
#endif
	bright->diffuseRGB = new float[] {1.0, 1.0, 1.0};
	bright->specularRGB = new float[] {1.0, 1.0, 1.0};
	bright->ambientRGB = new float[] {1.0, 1.0, 1.0};

	dotted = new LightCharacteristic();
#ifdef _DEBUG
	dotted->name = "Dotted";
#endif
	dotted->ambientRGB = new float[]{ 0.0 , 0.0 , 0.0 , 1.0 }; //������������� �������� �����
	dotted->diffuseRGB = new float[]{ 1.0 , 1.0 , 1.0 , 1.0 }; //������������� ������������� �����
	dotted->specularRGB = new float[]{ 1.0 , 1.0 , 1.0 , 1.0 }; // ������������� ����������� �����

	red = new LightCharacteristic();
#ifdef _DEBUG
	red->name = "Red";
#endif
	red->ambientRGB = new float[] { 1.0, 0.0, 0.0, 1.0 }; //������������� �������� �����
	red->diffuseRGB = new float[] { 1.0, 0.0, 0.0, 1.0 }; //������������� ������������� �����
	red->specularRGB = new float[] { 1.0, 0.0, 0.0, 1.0 }; // ������������� ����������� �����

	green = new LightCharacteristic();
#ifdef _DEBUG
	green->name = "Green";
#endif
	green->ambientRGB = new float[] { 0.0, 1.0, 0.0, 1.0 }; //������������� �������� �����
	green->diffuseRGB = new float[] { 0.0, 1.0, 0.0, 1.0 }; //������������� ������������� �����
	green->specularRGB = new float[] { 0.0, 1.0, 0.0, 1.0 }; // ������������� ����������� �����

	blue = new LightCharacteristic();
#ifdef _DEBUG
	blue->name = "Blue";
#endif
	blue->ambientRGB = new float[] { 0.0, 0.0, 1.0, 1.0 }; //������������� �������� �����
	blue->diffuseRGB = new float[] { 0.0, 0.0, 1.0, 1.0 }; //������������� ������������� �����
	blue->specularRGB = new float[] { 0.0, 0.0, 1.0, 1.0 }; // ������������� ����������� �����
}



void deleteLightCharacteristics() {
	delete bright;
	delete dotted;
	delete red;
	delete green;
	delete blue;
}