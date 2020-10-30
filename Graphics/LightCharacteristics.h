#pragma 
#include "LightCharacteristic.h"


LightCharacteristic* bright;
LightCharacteristic* dotted;
LightCharacteristic* l3;
LightCharacteristic* l4;

LightCharacteristic* getNextLight() {
	return nullptr;
}

void initLightCharacteristics() {
	bright = new LightCharacteristic();
	bright->diffuseRGB = new float[] {1.0, 1.0, 1.0};
	bright->specularRGB = new float[] {1.0, 1.0, 1.0};
	bright->ambientRGB = new float[] {1.0, 1.0, 1.0};

	dotted = new LightCharacteristic();
	dotted->ambientRGB = new float[]{ 0.0 , 0.0 , 0.0 , 1.0 }; //������������� �������� �����
	dotted->diffuseRGB = new float[]{ 1.0 , 1.0 , 1.0 , 1.0 }; //������������� ������������� �����
	dotted->specularRGB = new float[]{ 1.0 , 1.0 , 1.0 , 1.0 }; // ������������� ����������� �����
}



void deleteLightCharacteristics() {
	delete bright;
	delete dotted;
	delete l3;
	delete l4;
}