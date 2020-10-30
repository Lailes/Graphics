#pragma once

#ifdef _DEBUG
#include <string>
#endif

struct LightCharacteristic {
#ifdef _DEBUG
	std::string name;
#endif
	float* ambientRGB;
	float* specularRGB;
	float* diffuseRGB;

	~LightCharacteristic() {
		delete[] ambientRGB;
		delete[] specularRGB;
		delete[] diffuseRGB;
	}
};