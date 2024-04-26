#include <iostream>
#include <src/Visualiser.h>
#include <GLFW/glfw3.h>

int main() {
    Visualiser wizu;
    wizu.init(720, 480, "Program");
    wizu.run();
}

