#ifndef BASESHAPE_H
#define BASESHAPE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class BaseShape
{
protected:
    glm::mat4 model;
    int shaderProgram;
    GLuint iVAO,iVBO;
public:
    BaseShape(glm::mat4 model = glm::mat4(1.0f)) noexcept;
    virtual void prepare() noexcept = 0;
    virtual void draw() noexcept = 0;
    virtual ~BaseShape() noexcept;
};

#endif // BASESHAPE_H
