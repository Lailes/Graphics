#pragma once

namespace SceneObjests {
	class SceneObject {
	public:
		virtual void setStartPosition(float x, float y, float z) = 0;
		virtual void draw() = 0;
	protected:
		float x, y, z;
	};
}

