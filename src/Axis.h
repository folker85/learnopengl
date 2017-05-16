#pragma once

#include "Renderable.h"

enum AxisType
{
    X,
    Y,
    Z
};


class Axis : public Renderable
{
public:
    Axis(AxisType axis_type);
    ~Axis();

    virtual void render(const ShaderProgram& shader_program);

private:
    GLuint _VAO;
    GLuint _VBO;
};
