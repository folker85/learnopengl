#pragma once

#include <string>

#include <GL/glew.h>

class ShaderProgram
{
public:
    ShaderProgram(
        const std::string vertex_shader_path,
        const std::string fragment_shader_path);

    ~ShaderProgram();

    void use() const;
    void notUse() const;

    operator GLuint() const { return _program; }

private:
    ShaderProgram(const ShaderProgram&) = delete;
    ShaderProgram& operator=(const ShaderProgram&) = delete;

    const std::string readShaderSourceCode(const std::string path_to_source_code);
    GLuint createAndCompileShader(GLenum shader_type, std::string source_code);

private:
    GLuint _program;
};
