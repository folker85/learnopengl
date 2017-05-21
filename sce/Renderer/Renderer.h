#pragma once

namespace sce
{
	 // Forward declarations
	class Scene;
	class Camera;
	class ShaderProgram;

	class Renderer
	{
	public:
		void render();
		void setupScene(Scene* scene_to_render);

		void setupCamera(Camera* camera);
		Camera* getActiveCamera();

		void setupBasicShader(ShaderProgram* shader);
		ShaderProgram* getBasicShader();

	private:
		Scene* _scene;
		Camera* _active_camera;
		ShaderProgram* _shader;
	};
}
