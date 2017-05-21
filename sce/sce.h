#pragma once

#include "OpenGL\FunctionLoader.h"
#include "OpenGL\ContextStateManager.h"
#include "Renderer\Renderer.h"
#include "Renderer\ShaderProgram.h"
#include "Scene\Scene.h"
#include "Camera\Camera.h"

#include "Mesh\Renderable.h"
#include "Mesh\Cube.h"

namespace sce
{
	Renderer* init(int width, int height);
}
