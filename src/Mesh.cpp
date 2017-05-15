#include "Mesh.h"

Mesh::Mesh(const std::vector<Vertex>& vertices)
{
	_vertices = vertices;

	setup();	
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &_VAO);
}

void Mesh::render(const ShaderProgram& shader_program)
{
	glBindVertexArray(_VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}

void Mesh::setup()
{
	glGenVertexArrays(1, &_VAO);
    glBindVertexArray(_VAO);

	glGenBuffers(1, &_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, _VBO);
	glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(Vertex),
		&_vertices[0], GL_STATIC_DRAW);

	// Position attribute
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
	
	glBindVertexArray(0);
    glDeleteBuffers(1, &_VBO);
}
