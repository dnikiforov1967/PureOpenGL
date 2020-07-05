#ifndef SHADERCONTROLLER_H
#define SHADERCONTROLLER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

class ShaderController
{
public:
    ShaderController();
    int allocateShaders(const char*, const char*);
};

#endif // SHADERCONTROLLER_H
