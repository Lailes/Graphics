#include "SceneObject.h"

void SceneObject::visibilty(bool visible) {
	this->display = visible;
}

bool SceneObject::isVisible() {
	return display;
}
