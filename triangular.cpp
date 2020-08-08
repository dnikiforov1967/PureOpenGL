#include "triangular.h"
#include "shadercontroller.h"

Triangular::Triangular(const Point &a, const Point &b, const Point &c, glm::mat4 model) noexcept :
    BaseShape(model), va(a), vb(b), vc(c)
{

}

void Triangular::prepare() noexcept {
    float line[] = {
        va.getX(), va.getY(), va.getZ(), 1.0f, 1.0f, 1.0f,
        vb.getX(), vb.getY(), vb.getZ(), 1.0f, 1.0f, 1.0f,
        vc.getX(), vc.getY(), vc.getZ(), 1.0f, 1.0f, 1.0f
    };
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
    glBufferData(GL_ARRAY_BUFFER, sizeof(line), line, GL_STATIC_DRAW);
    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);
}

void Triangular::draw() noexcept {
    glBindVertexArray(iVAO);
    glUseProgram(shaderProgram);
    glDrawArrays(GL_LINE_LOOP, 0, 3);
}
