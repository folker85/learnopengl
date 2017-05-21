#pragma once

// GLM
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace sce
{
	class Camera
	{
	public:
		Camera();

		inline glm::mat4 getVP() const { return _vp; }
		inline glm::mat4 getView() const { return _view; }
		inline glm::mat4 getProjection() const { return _projection; }

	private:
		glm::mat4 _vp;
		glm::mat4 _view;
		glm::mat4 _projection;
	};
}
