
#include "Camera.h"

namespace sce
{
	Camera::Camera()
	{
		_view = glm::lookAt(glm::vec3(0.0, 2.0, 0.0), glm::vec3(0.0, 0.0, -4.0), glm::vec3(0.0, 1.0, 0.0));
		_projection = glm::perspective(45.0f, 1.0f * 800 / 600, 0.1f, 10.0f);
		_vp = _projection * _view;
	}
}
