#pragma once

#include "ShaderProgram.h"
#include "Camera.h"

// Abstract base class for all renderables.
class Renderable
{
public:
	virtual void render(const ShaderProgram& shader_program, const Camera& camera) = 0;
};
