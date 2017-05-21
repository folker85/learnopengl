
#include "Scene.h"
#include "..\Renderer\Renderer.h"
#include "..\Mesh\Mesh.h"
#include "..\Renderer\ShaderProgram.h"

namespace sce
{
	void Scene::render(Renderer* renderer)
	{
		Camera* camera = renderer->getActiveCamera();
		ShaderProgram* shader = renderer->getBasicShader();

		for (auto r : _nodes)
		{
			r->render(*shader, *camera);
		}
	}

	void Scene::addNode(Mesh* node)
	{
		// todo: what if already present
		// todo: Who will delete nodes ?
		_nodes.push_back(node);
	}
}
