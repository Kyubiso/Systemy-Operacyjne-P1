#ifndef VISUALISER_HPP
#define VISUALISER_HPP

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


class Visualiser {
private:
    GLFWwindow* window;

public:
    Visualiser();
    ~Visualiser();
    bool init(int width, int height, const char* title);
    void run();
};

#endif // VISUALISER_HPP
