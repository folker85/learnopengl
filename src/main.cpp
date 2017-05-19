
 // STD
#include <iostream>
#include <vector>

 // GLEW
#define GLEW_STATIC
#include <GL/glew.h>

 // GLFW
#include <GLFW\glfw3.h>

 // SOIL
#include <SOIL.h>

 // GLM
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

 // PROJECT
#include "ShaderProgram.h"
#include "Renderable.h"
#include "Mesh.h"
#include "Vertex.h"
#include "Cube.h"

void setupViewport(GLFWwindow* window);
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

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	setupViewport(window);

    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	const std::string vertex_shader_source_code_path = "shaders\\Simple.vertex";
	const std::string fragment_shader_source_code_path = "shaders\\Simple.fragment";
	ShaderProgram program(vertex_shader_source_code_path, fragment_shader_source_code_path);

	Vertex v0 = { 0.5f,  0.5f, 0.0f }; // Top Right
	Vertex v1 = { 0.5f, -0.5f, 0.0f }; // Bottom Right
	Vertex v2 = { -0.5f, -0.5f, 0.0f }; // Bottom Left
	Vertex v3 = { -0.5f,  0.5f, 0.0f }; // Top Left
	std::vector<Vertex> vertices = { v0, v1, v2, v3};

	std::vector<GLuint> indices =
	{  // Note that we start from 0!
		0, 1, 3, // First Triangle
		1, 2, 3  // Second Triangle
	};

	Renderable* rectangle = new Mesh(vertices, indices);

    Cube cube;
    cube.setModelMatrix(glm::translate(glm::mat4(1.0f), glm::vec3(0.0, 0.0, -4.0)));
    auto model_matrix = cube.getModelMatrix();
        
    Camera camera;

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		// Render
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        auto _model_matrix = model_matrix;
        auto trans = glm::rotate(_model_matrix, (GLfloat)glfwGetTime() / 40 * 50.0f, glm::vec3(0.0f, 1.0f, 0.0f));
        cube.setModelMatrix(trans);
		//rectangle->render(program);
        cube.render(program, camera);

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