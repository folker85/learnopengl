#include "Mesh.h"
#include "..\Camera\Camera.h"

namespace sce
{
	Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices)
	{
		_vertices = vertices;
		_indices = indices;

		setup();
	}

	Mesh::~Mesh()
	{
		glDeleteVertexArrays(1, &_VAO);
	}

	void Mesh::render(const ShaderProgram& shader_program, const Camera& camera)
	{
		shader_program.use();

		glm::mat4 mvp = camera.getVP() * _model_matrix;
		GLuint mvp_loc = glGetUniformLocation(shader_program, "mvp");
		glUniformMatrix4fv(mvp_loc, 1, GL_FALSE, glm::value_ptr(mvp));

		glBindVertexArray(_VAO);
		glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		shader_program.notUse();
	}

	void Mesh::setup()
	{
		glGenVertexArrays(1, &_VAO);
		glBindVertexArray(_VAO);

		glGenBuffers(1, &_VBO);
		glBindBuffer(GL_ARRAY_BUFFER, _VBO);
		glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(Vertex),
			&_vertices[0], GL_STATIC_DRAW);

		glGenBuffers(1, &_EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(GLuint),
			&_indices[0], GL_STATIC_DRAW);

		// Position attribute
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);

		glBindVertexArray(0);

		glDeleteBuffers(1, &_VBO);
		glDeleteBuffers(1, &_EBO);
	}
}
