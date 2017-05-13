
#include <iostream>
#include <vector>

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW\glfw3.h>

#include "ShaderProgram.h"
#include "Renderable.h"
#include "Mesh.h";
#include "Vertex.h"

void setupViewport(GLFWwindow* window);
void setupCallbacks(GLFWwindow* window);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	setupCallbacks(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	setupViewport(window);

	const std::string vertex_shader_source_code_path = "shaders\\Simple.vertex";
	const std::string fragment_shader_source_code_path = "shaders\\Simple.fragment";
	ShaderProgram program(vertex_shader_source_code_path, fragment_shader_source_code_path);

	Vertex v1 = { 0.5f, -0.5f, 0.0f };
	Vertex v2 = { -0.5f, -0.5f, 0.0f };
	Vertex v3 = { 0.0f,  0.5f, 0.0f };
	std::vector<Vertex> triangle_vertices = { v1, v2, v3 };
	Renderable* triangle = new Mesh(triangle_vertices);
	
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		// Render
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		program.use();

		triangle->render();

		glfwSwapBuffers(window);
	}

	glfwTerminate();

	return 0;
}

void setupViewport(GLFWwindow* window)
{
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
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