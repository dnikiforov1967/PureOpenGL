#ifndef COORDINATES_H
#define COORDINATES_H

#include "baseshape.h"

class XYZAxes : protected BaseShape
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
            "layout (location = 1) in vec3 aColor;\n"
            "out vec3 axColor;\n"
            "uniform mat4 model;\n"
            "void main()\n"
            "{\n"
            "gl_Position = model*vec4(aPos, 1.0f);\n"
            "axColor = aColor;\n"
            "}\n\0";
    const char *fragmentShaderSource = "#version 330 core\n"
        "in vec3 axColor;\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
        "}\n\0";
public:
    XYZAxes(glm::mat4 model = glm::mat4(1.0f)) noexcept;
    void prepare() noexcept override;
    void draw() noexcept override;
};

#endif // COORDINATES_H
