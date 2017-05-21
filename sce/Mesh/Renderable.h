#pragma once

//#include "ShaderProgram.h"
//#include "Camera.h"

// Abstract base class for all renderables.

class ShaderProgram;
class Camera;

namespace sce
{
	class Renderable
	{
	public:
		virtual void render(const ShaderProgram& shader_program, const Camera& camera);
	};
}
