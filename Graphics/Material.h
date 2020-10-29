#pragma once

struct Material {
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
