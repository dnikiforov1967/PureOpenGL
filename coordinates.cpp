#include "coordinates.h"
#include "shadercontroller.h"

XYZAxes::XYZAxes(glm::mat4 model) noexcept
{
    this->model = model;
}

void XYZAxes::prepare() noexcept
{
    ShaderController sc;
    shaderProgram = sc.allocateShaders(vertexShaderSource, fragmentShaderSource);
    int modelLoc = glGetUniformLocation(shaderProgram, "model");
    glUseProgram(shaderProgram);
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
}

void XYZAxes::draw() noexcept {

}

