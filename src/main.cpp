#include <Eigen/Dense>
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

using namespace std;

int main() {
	cout << "Orbit Simulator starting..." << endl;

	// Initialize GLFW
	if (!glfwInit()) {
		cerr << "Failed to initialize GLFW." << endl;
		return -1;
	}

	// Create program window
	GLFWwindow* window = glfwCreateWindow(800, 600, "Orbit Simulator", NULL, NULL);
	if (!window) {
		cerr << "Failed to create GLFW window." << endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	// Main program loop
	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
	
}