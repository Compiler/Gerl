#include <stdio.h>
#include "Core/GerlCore.h"
#include <GLFW/glfw3.h>
//#include <glad/gl.h>

int main(){
	if(!glfwInit()) printf("Failed to init glfw");
   	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);//version 4.6 Core profile
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	glfwWindowHint(GLFW_SAMPLES, 4);
	GLFWwindow* window = glfwCreateWindow(640, 480, "C OPENGL", NULL, NULL);
	struct GerlCore core;
	core.number = 4;
	printf("Hello %d", core.number);

	float time = glfwGetTime();
	while(glfwGetTime() - time <= 5) {
		glfwPollEvents();
	}
	
    return 4;
}







	


	// glfwDestroyWindow(window);
	// glfwTerminate();