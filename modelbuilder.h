#ifndef MODELBUILDER_H
#define MODELBUILDER_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class ModelBuilder
{
public:
    ModelBuilder() noexcept;
    void routeAroudX(float angle) noexcept;
    void routeAroudY(float angle) noexcept;
    void routeAroudZ(float angle) noexcept;
    glm::mat4 build() noexcept;
private:
    float angleX, angleY, angleZ;
};

#endif // MODELBUILDER_H
