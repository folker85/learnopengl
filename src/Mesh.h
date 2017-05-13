#pragma once

#include <vector>

#include "Renderable.h"
#include "ShaderProgram.h"
#include "Vertex.h"

class Mesh : public Renderable
{
public:
	Mesh(const std::vector<Vertex>& vertices);

	virtual void render();

private:
	void setup();

private:
	GLuint _VAO;
	GLuint _VBO;

	std::vector<Vertex> _vertices;
};

