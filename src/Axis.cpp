
#include <vector>

#include "Axis.h"
#include "Vertex.h"

Axis::Axis(AxisType axis_type)
{
    glGenVertexArrays(1, &_VAO);
    glBindVertexArray(_VAO);

    Vertex v0 = { 0.0f,  0.0f, 0.0f };
    Vertex v1;
    switch (axis_type)
    {
    case X:
    {
        v1 = { 0.5f, 0.0f, 0.0f }; // not sure about direction
        break;
    }
    case Y:
    { 
        v1 = { 0.0f, 0.5f, 0.0f }; // not sure about direction
        break;
    }
    case Z:
    { 
        v1 = { 0.0f, 0.0f, -0.5f }; // not sure about direction
        break;
    }
    }

    std::vector<Vertex> vertices = { v0, v1 };


    glGenBuffers(1, &_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex),
        &vertices[0], GL_STATIC_DRAW);

    // Position attribute
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);

    glBindVertexArray(0);

    glDeleteBuffers(1, &_VBO);
}

Axis::~Axis()
{
    glDeleteVertexArrays(1, &_VAO);
}

void Axis::render(const ShaderProgram& shader_program)
{
    glBindVertexArray(_VAO);
    glDrawArrays(GL_LINES, 0, 2);
    glBindVertexArray(0);
}
