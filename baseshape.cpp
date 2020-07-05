#include "baseshape.h"

BaseShape::BaseShape(glm::mat4 model) noexcept
{
    this->model = model;
}

BaseShape::~BaseShape() noexcept
{
    glDeleteVertexArrays(1, &iVAO);
    glDeleteBuffers(1, &iVBO);
    glDeleteProgram(shaderProgram);
}

