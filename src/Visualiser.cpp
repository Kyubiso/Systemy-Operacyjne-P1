#include "Visualiser.h"

#include <cmath>

Visualiser::Visualiser() : window(nullptr) {}

Visualiser::~Visualiser() {
    if (window != nullptr) {
        glfwDestroyWindow(window);
        glfwTerminate();
    }
}

bool Visualiser::init(int width, int height, const char* title) {
    // Inicjalizacja biblioteki GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return false;
    }

    // Ustawienie wersji OpenGL (opcjonalne)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Utworzenie okna
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (window == nullptr) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }

    // Ustawienie kontekstu OpenGL dla okna
    glfwMakeContextCurrent(window);

    // Inicjalizacja GLEW (lub innego narzędzia do zarządzania rozszerzeniami OpenGL)
    glewExperimental = GL_TRUE; // Potrzebne w niektórych systemach
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return false;
    }

    return true;
}

void Visualiser::run() {
    // Pętla renderowania
    float color = 0.0f;

    while (!glfwWindowShouldClose(window)) {
        color+= 0.001f;
        // Ustawienie koloru tła na niebieski tylko podczas czyszczenia bufora koloru
        glClearColor(0.5f, color, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glPointSize(5.0); // Ustawienie rozmiaru punktu na 5 pikseli
        glBegin(GL_POINTS); // Rozpoczęcie rysowania punktu
        glVertex2f(0.0, 0.0); // Współrzędne punktu (0,0)
        glEnd(); // Zakończenie rysowania punktu
        GLenum error = glGetError();
        if (error != GL_NO_ERROR) {
            std::cerr << "OpenGL error: " << error << std::endl;
        }
        glfwSwapBuffers(window);

        // Obsługa zdarzeń
        glfwPollEvents();
    }
}