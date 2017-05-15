#pragma once

#include "ShaderProgram.h"

// Abstract base class for all renderables.
class Renderable
{
public:
	virtual void render(const ShaderProgram& shader_program) = 0;
};
