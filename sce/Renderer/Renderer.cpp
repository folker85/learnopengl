
#include <GL/glew.h>

#include <exception>

#include "Renderer.h"
#include "..\Scene\Scene.h"
#include "..\Camera\Camera.h"

namespace sce
{
	void Renderer::render()
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		if (!_scene)
		{
			throw std::exception("First need to setup scene!");
		}

		if (!_active_camera)
		{
			throw std::exception("First need to setup active camera!");
		}
	
		_scene->render(this);
	}

	void Renderer::setupScene(Scene* scene_to_render)
	{
		_scene = scene_to_render;
	}

	void Renderer::setupCamera(Camera* camera)
	{
		_active_camera = camera;
	}

	Camera * Renderer::getActiveCamera()
	{
		return _active_camera;
	}

	void Renderer::setupBasicShader(ShaderProgram* shader)
	{
		_shader = shader;
	}

	ShaderProgram* Renderer::getBasicShader()
	{
		return _shader;
	}
}
