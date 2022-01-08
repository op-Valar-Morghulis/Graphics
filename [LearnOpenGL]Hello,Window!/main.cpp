#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main() {
    // Init (gl for window) glfw
    glfwInit();
    // Configure glfw by using glfwWindowHint
    // All parameters can be found in https://www.glfw.org/docs/latest/window.html#window_hints
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // Create Window object
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if(window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    // GLFW sets window's context to the current thread's main context
    glfwMakeContextCurrent(window);
    // Check if glad is working correctly
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    // Tell openGL the size of window to be rendered
    glViewport(0, 0, 800, 600); // first two parameters control the location of left corner
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    /* Render Loop
     * glfwWindowShouldClose check whether GLFW is asked to exit
     * glfwSwapBuffers will swap the color buffer
     * glfwPollEvents will check is there any events triggered */
    while(!glfwWindowShouldClose(window)) {
        processInput(window);

        // Rendering orders ....
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
        // glClear receive a Buffer Bit to specify the buffer to be clean
    }
    // Double buffer will be used to solve the Image flickering problem
    glfwTerminate();
    return 0;
}

// Callback function used to adjust the size of window
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}