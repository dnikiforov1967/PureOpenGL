#include "coordinates.h"
#include "shadercontroller.h"

XYZAxes::XYZAxes(glm::mat4 model) noexcept : BaseShape(model)
{
}

void XYZAxes::prepare() noexcept
{
    ShaderController sc;
    shaderProgram = sc.allocateShaders(vertexShaderSource, fragmentShaderSource);
    int modelLoc = glGetUniformLocation(shaderProgram, "model");
    glUseProgram(shaderProgram);
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    glGenVertexArrays(1, &iVAO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(iVAO);
    glGenBuffers(1, &iVBO);
    glBindBuffer(GL_ARRAY_BUFFER, iVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(axes), axes, GL_STATIC_DRAW);
    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
    //glEnableVertexAttribArray(1);
}

void XYZAxes::draw() noexcept {
    glBindVertexArray(iVAO);
    glUseProgram(shaderProgram);
    glDrawArrays(GL_LINES, 0, 2);
    glDrawArrays(GL_LINES, 2, 2);
    glDrawArrays(GL_LINES, 4, 2);
}

