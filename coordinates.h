#ifndef COORDINATES_H
#define COORDINATES_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class XYZAxes
{
    float axes[18] = {
        // positions         // colors
        0.9f, 0.0f, 0.0f,
       -0.9f, 0.0f, 0.0f,
        0.0f, 0.9f, 0.0f,
        0.0f,-0.9f, 0.0f,
        0.0f, 0.0f, 5.9f,
        0.0f, 0.0f,-5.9f
    };
    const char *vertexShaderSource = "#version 330 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "out vec3 ourColor;\n"
            "uniform mat4 model;\n"
            "void main()\n"
            "{\n"
            "gl_Position = model*vec4(aPos, 1.0f);\n"
            "}\n\0";
    const char *fragmentShaderSource = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(1.0f,1.0f,1.0f, 1.0);\n"
        "}\n\0";
    glm::mat4 model;
    int shaderProgram;
public:
    XYZAxes(glm::mat4 model = glm::mat4(1.0f)) noexcept;
    void prepare() noexcept;
    void draw() noexcept;
};

#endif // COORDINATES_H
