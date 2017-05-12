
#include <iostream>
#include <fstream>
#include <sstream>

#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(
    const std::string vertex_shader_path,
    const std::string fragment_shader_path)
{
    auto vertex_shader_source_code = readShaderSourceCode(vertex_shader_path);
    auto fragment_shader_source_code = readShaderSourceCode(fragment_shader_path);

    auto vertex_shader = createAndCompileShader(GL_VERTEX_SHADER, vertex_shader_source_code);
    auto fragment_shader = createAndCompileShader(GL_FRAGMENT_SHADER, fragment_shader_source_code);

    _program = glCreateProgram();
    glAttachShader(_program, vertex_shader);
    glAttachShader(_program, fragment_shader);
    glLinkProgram(_program);

    GLint success;
    GLchar infoLog[512];
    glGetProgramiv(_program, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(_program, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
}

void ShaderProgram::use()
{
    glUseProgram(_program);
}

const std::string ShaderProgram::readShaderSourceCode(const std::string path_to_source_code)
{
    std::ifstream shader_file;
    std::stringstream shader_stream;

    // ensures ifstream object can throw exceptions:
    shader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try
    {
        // Open file
        shader_file.open(path_to_source_code.c_str());

        // Read file buffer content into stream
        shader_stream << shader_file.rdbuf();

        // close file handler
        shader_file.close();
    }
    catch (std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }

    return shader_stream.str();
}

GLuint ShaderProgram::createAndCompileShader(GLenum shader_type, const std::string source_code)
{
    const GLchar* shader_code = source_code.c_str();

    GLuint shader;
    shader = glCreateShader(shader_type);
    glShaderSource(shader, 1, &shader_code, NULL);
    glCompileShader(shader);

    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    };

    return shader;
}
