
 // ENGINE
#include <sce/sce.h>

 // STD
#include <iostream>
#include <vector>

 // GLFW
#include <GLFW\glfw3.h>

 // SOIL
#include <SOIL.h>

 // GLM
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


void setupCallbacks(GLFWwindow* window);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

const GLuint WIDTH = 800, HEIGHT = 600;

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	setupCallbacks(window);

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);

	 // Init engine
	sce::Renderer* renderer = sce::init(width, height);
	sce::Scene scene;
	sce::Camera camera;
	renderer->setupScene(&scene);
	renderer->setupCamera(&camera);

	const std::string vertex_shader_source_code_path = "shaders\\Simple.vertex";
	const std::string fragment_shader_source_code_path = "shaders\\Simple.fragment";
	sce::ShaderProgram program(vertex_shader_source_code_path, fragment_shader_source_code_path);

	renderer->setupBasicShader(&program);

	//Vertex v0 = { 0.5f,  0.5f, 0.0f }; // Top Right
	//Vertex v1 = { 0.5f, -0.5f, 0.0f }; // Bottom Right
	//Vertex v2 = { -0.5f, -0.5f, 0.0f }; // Bottom Left
	//Vertex v3 = { -0.5f,  0.5f, 0.0f }; // Top Left
	//std::vector<Vertex> vertices = { v0, v1, v2, v3};

	//std::vector<GLuint> indices =
	//{  // Note that we start from 0!
	//	0, 1, 3, // First Triangle
	//	1, 2, 3  // Second Triangle
	//};

	//Renderable* rectangle = new Mesh(vertices, indices);

    sce::Cube cube;
    cube.setModelMatrix(glm::translate(glm::mat4(1.0f), glm::vec3(0.0, 0.0, -4.0)));
    auto model_matrix = cube.getModelMatrix();
       
	sce::Cube cube1;
	cube1.setModelMatrix(glm::translate(glm::mat4(1.0f), glm::vec3(0.0, 0.0, -3.0)));
	scene.addNode(&cube);
	scene.addNode(&cube1);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		auto _model_matrix = model_matrix;
		auto trans = glm::rotate(_model_matrix, (GLfloat)glfwGetTime() / 40 * 50.0f, glm::vec3(0.0f, 1.0f, 0.0f));
		cube.setModelMatrix(trans);

		renderer->render();
       
		//rectangle->render(program);

		glfwSwapBuffers(window);
	}

	glfwTerminate();

	return 0;
}

void setupCallbacks(GLFWwindow* window)
{
	glfwSetKeyCallback(window, key_callback);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	std::cout << key << std::endl;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}