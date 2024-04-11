#include "glew.h"
#include "glfw3.h"
#include <cmath>
#include <iostream>


int main() {

    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(500, 500, "Plotting the drag force vs speed", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    glClearColor(0, 0, 0, 1.0f);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_LINES);
        // Draw X and Y axis
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(-1.0, -0.9);
        glVertex2f(1.0, -0.9);
        glVertex2f(-0.9, 1.0);
        glVertex2f(-0.9, -1.0);

        for (double i = -0.9; i < 1; i+=0.2) // Draws x-axis tick marks (Speed)
        {
            glVertex2f(i, -.95);
            glVertex2f(i, -.85);

        }
        for (double i = -0.72; i < 1; i += 0.18) // Draws y-axis tick marks (Force)
        {
            glVertex2f(-.95, i);
            glVertex2f(-0.85, i);
        }

        // Plotting the equation for the drag force as a function of speed
        // Assume fully-loaded Cessna 172 at sea level:
        //          air density =  1.225 kg/m^3
        //          wing area = 16.17 m^2
        //          zero-lift drag coefficient = 0.0341
        //          Weight = 1000 kg
        //          Wing aspect ratio = 7.52
        //          Oswalds efficiency = 0.7

        const double pi = 3.1415926535;

        double rho = 1.225;
        double S = 16.17;
        double C_D0 = 0.0341;
        double W = 1000.0;
        double AR = 7.52;
        double eO = 0.7;

        glColor3f(0.0, 1.0, 0.0);
        
        double x;
        double y;

        for (double i = 20.0; i <= 80.0; i += 0.005)
        {
            double x = (i / 50) - 0.9; // scales down the speed to be graphed properly
            double y = (0.5 * rho * S * C_D0 * i * i) + ( ( 2.0 * W * W ) / (rho * pi * AR * eO * S * i * i) );
            y = y / 1111 - 0.9; // scales down the forces to be graphed properly

            glVertex2f(x, y - 0.001);
            glVertex2f(x, y);
        }

        //for (float i = 0; i < 2 * 3.14159; i += 0.001) {
        //    float x = (2 * i - 3.14159) / 3.14159;
        //    float y = sin(i);
        //    glVertex2f(x, y - 0.001);
        //    glVertex2f(x, y);
        //}
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    std::cout << "Each tick mark on the x-axis are increments of 10 m/s" << std::endl; // 0 m/s -> 80 m/s
    std::cout << "Each tick mark on the y-axis are increments of 200 Newtons" << std::endl; // 0 Newtons -> 2,000 Newtons
    return 0;
}