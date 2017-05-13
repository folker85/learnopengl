#pragma once

#include <vector>

#include "Renderable.h"
#include "ShaderProgram.h"
#include "Vertex.h"

class Mesh : public Renderable
{
public:
	Mesh(const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices);

	virtual void render();

private:
	void setup();

private:
	GLuint _VAO;
	GLuint _VBO;
	GLuint _EBO;

	std::vector<Vertex> _vertices;
	std::vector<GLuint> _indices;
};

