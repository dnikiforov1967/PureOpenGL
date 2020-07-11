#include "modelbuilder.h"

ModelBuilder::ModelBuilder() noexcept : angleX(0.0f), angleY(0.0f), angleZ(0.0f)
{

}

ModelBuilder& ModelBuilder::routeAroudX(float angle) noexcept
{
    angleX = angle;
    return *this;
}

ModelBuilder& ModelBuilder::routeAroudY(float angle) noexcept
{
    angleY = angle;
    return *this;
}

ModelBuilder& ModelBuilder::routeAroudZ(float angle) noexcept
{
    angleZ = angle;
    return *this;
}

glm::mat4 ModelBuilder::build() noexcept
{
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(angleX), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(angleY), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(angleZ), glm::vec3(0.0f, 0.0f, 1.0f));
    return model;
}
