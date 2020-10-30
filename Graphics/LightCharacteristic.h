#pragma once


struct LightCharacteristic {
	float* ambientRGB;
	float* specularRGB;
	float* diffuseRGB;

	~LightCharacteristic() {
		delete[] ambientRGB;
		delete[] specularRGB;
		delete[] diffuseRGB;
	}
};