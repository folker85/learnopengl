#pragma once

#include <vector>

#include "Renderable.h"
#include "ShaderProgram.h"
#include "Vertex.h"

class Mesh : public Renderable
{
public:
	Mesh(const std::vector<Vertex>& vertices);
    ~Mesh();

	virtual void render(const ShaderProgram& shader_program);

private:
    Mesh(const Mesh&) = delete;
    Mesh& operator=(const Mesh&) = delete;

	void setup();

private:
	GLuint _VAO;
	GLuint _VBO;

	std::vector<Vertex> _vertices;
};

