#pragma once

#ifdef _DEBUG
#include <string>
#endif

struct Material {
#ifdef _DEBUG
	std::string name;
#endif
	float* rgb;
	float* ambientRGB;
	float* specularRGB;
	float* diffuseRGB;
	float emission;
	float shiness;

	~Material(){
		delete[] rgb;
		delete[] ambientRGB;
		delete[] specularRGB;
		delete[] diffuseRGB;
	}
};
