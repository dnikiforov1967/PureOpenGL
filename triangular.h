#ifndef TRIANGULAR_H
#define TRIANGULAR_H

#include "point.h"
#include "baseshape.h"

class Triangular : protected BaseShape
{
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
    Point va,vb,vc;
public:
    Triangular() = delete;
    Triangular(const Point&, const Point&, const Point&, glm::mat4 model = glm::mat4(1.0f)) noexcept;
    void prepare() noexcept;
    void draw() noexcept;
};

#endif // TRIANGULAR_H
