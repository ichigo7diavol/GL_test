#include <iostream>
#include "linmath.h"

#include <GL/glew.h>

#define GLFW_DLL
#include "GLFW/glfw3.h"

static const char* vertex_shader_text =
"uniform mat4 MVP;\n"
"attribute vec3 vCol;\n"
"attribute vec2 vPos;\n"
"varying vec3 color;\n"
"void main()\n"
"{\n"
"    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
"    color = vCol;\n"
"}\n";

void resize(GLFWwindow * _pwin, int w, int h)
{
    glViewport(0, 0, w, h); // изменить размер после ресайза

    return;
}

void mouseHandler (GLFWwindow * _pwin, double x, double y)
{
    glClearColor(0xFF, (float)x/0xFF, (float)y/0xFF, 0.0);

    std::cout << x << " " << y << std::endl;
}

void setup(GLFWwindow * _pwin)
{
    glClearColor(0xFF, 0xFF, 0xFF, 0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0); // настроить систему координат
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glfwSetWindowSizeCallback(_pwin, resize); // callback на ресайз окна
    glfwSetCursorPosCallback(_pwin, mouseHandler);

    return;
}

int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glewInit();



    setup(window);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(0.0, 0.0, 0.0);

        // Draw a polygon with specified vertices.
        glBegin(GL_POLYGON);

        glVertex3f(20.0, 20.0, 0.0);
        glVertex3f(80.0, 20.0, 0.0);
        glVertex3f(80.0, 80.0, 0.0);
        glVertex3f(20.0, 80.0, 0.0);

        glEnd();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
