#pragma once

#include <string>

#include <GL/glew.h>

class ShaderProgram
{
private:
    GLuint _program;

public:
    ShaderProgram(
        const std::string vertex_shader_path,
        const std::string fragment_shader_path);

    void use();

private:
    const std::string readShaderSourceCode(const std::string path_to_source_code);
    GLuint createAndCompileShader(GLenum shader_type, std::string source_code);
};
