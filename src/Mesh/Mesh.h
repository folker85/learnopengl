#pragma once

#include <vector>

// GLM
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Renderable.h"
#include "ShaderProgram.h"
#include "Vertex.h"

class Mesh : public Renderable
{
public:
    Mesh() {}
	Mesh(const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices);
    ~Mesh();

	virtual void render(const ShaderProgram& shader_program, const Camera& camera);

    inline glm::mat4 getModelMatrix() const { return _model_matrix; }
    inline void setModelMatrix(const glm::mat4& m) { _model_matrix = m; }

protected:
	void setup();

private:
    Mesh(const Mesh&) = delete;
    Mesh& operator=(const Mesh&) = delete;

protected:
    std::vector<Vertex> _vertices;
    std::vector<GLuint> _indices;

private:
	GLuint _VAO;
	GLuint _VBO;
	GLuint _EBO;

    glm::mat4 _model_matrix;
};

