#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <cmath>

#include "shadercontroller.h"
#include "coordinates.h"
#include "modelbuilder.h"
#include "triangular.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

float line[] = {
    0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
    0.0f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f,
    0.0f, 0.0f, 0.5f, 1.0f, 1.0f, 1.0f
};

const char *vertexShaderSource2 = "#version 330 core\n"
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



int main()
{

    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }


    ModelBuilder modelBuilder;
    glm::mat4 model = modelBuilder
            .routeAroudX(-45.0f)
            .routeAroudZ(-120.0f)
            .build();

    //glm::mat4 model = glm::mat4(1.0f);
    //model = glm::rotate(model, glm::radians(-45.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    //model = glm::rotate(model, glm::radians(-120.0f), glm::vec3(0.0f, 0.0f, 1.0f));





    XYZAxes xyzAxes(model);
    xyzAxes.prepare();

    Triangular tr(Point(0.5f, 0.0f, 0.0f), Point(0.0f, 0.5f, 0.0f), Point(0.0f, 0.0f, 0.5f), model);
    tr.prepare();

    unsigned int vboFigure, VAO2;
    ShaderController sc;
    int shaderProgram2 = sc.allocateShaders(vertexShaderSource2, fragmentShaderSource);

    int modelLoc2 = glGetUniformLocation(shaderProgram2, "model");
    glUseProgram(shaderProgram2);
    glUniformMatrix4fv(modelLoc2, 1, GL_FALSE, glm::value_ptr(model));

    glGenVertexArrays(1, &VAO2);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO2);
    glGenBuffers(1, &vboFigure);
    glBindBuffer(GL_ARRAY_BUFFER, vboFigure);
    glBufferData(GL_ARRAY_BUFFER, sizeof(line), line, GL_STATIC_DRAW);
    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);

        // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
        //glBindBuffer(GL_ARRAY_BUFFER, 0);
        // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
        // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
        //glBindVertexArray(0);


        // uncomment this call to draw in wireframe polygons.
        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        // now render the triangle
        //glBindVertexArray(VAO);

        // render loop
        // -----------
        while (!glfwWindowShouldClose(window))
        {
            // input
            processInput(window);

            // render
            // clear the colorbuffer
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            xyzAxes.draw();

            tr.draw();

            /*glBindVertexArray(VAO2);
            glUseProgram(shaderProgram2);
            glDrawArrays(GL_LINE_LOOP, 0, 3);*/

            // swap buffers and poll IO events
            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        // optional: de-allocate all resources once they've outlived their purpose:
        // ------------------------------------------------------------------------

        // glfw: terminate, clearing all previously allocated GLFW resources.
        // -------------------------------
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

