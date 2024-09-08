#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main() {

	// Init GLFW
	glfwInit();

	// Tell GL:FW what version og OpenGL we are using
	// IN this case we are using ver 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Tell GLFW we are using the CORE profile
	// so that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// create a GLFWwindow of 800x800 pixels, naming it "test"
	GLFWwindow* window = glfwCreateWindow(800, 800, "test", NULL, NULL);


	// error check for creating the GLFW window
	if (window == NULL) {
		std::cout << "failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// introduce the window into the current context 
	glfwMakeContextCurrent(window);

	// Load GLAD so it configures OpenGL
	gladLoadGL();

	// Specifies the viewport of OpenGL in this window from x: 0, 800 and y: 0, 800
	glViewport(0, 0, 800, 800);

	// Specify the color of the background
	glClearColor(0.0f, 0.13f, 0.17f, 1.0f);
	// Clean the back buffer and assign the new color to it
	glClear(GL_COLOR_BUFFER_BIT);
	// Swap the buffer with the new buffer
	glfwSwapBuffers(window);

	// Main while loop
	while (!glfwWindowShouldClose(window)) {
		// Take care of all GLFW events
		glfwPollEvents();
	}

	// Destroys the window
	glfwDestroyWindow(window);


	// terminates the glfw instance
	glfwTerminate();
	return 0;
}
