#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <Core/GerlCore.h>

int main(){
	if(!glfwInit()) printf("Failed to init glfw");
	
	
   	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);//version 4.6 Core profile
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	glfwWindowHint(GLFW_SAMPLES, 4);
	GLFWwindow* window = glfwCreateWindow(640, 480, "C OPENGL", NULL, NULL);
	glfwMakeContextCurrent(window);
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Something went wrong!\n");
	}

	struct GerlCore core;
	core.number = 4;
	float time = glfwGetTime();
	float elapsed = glfwGetTime() - time;
	printf("%f\n", elapsed);
	while( elapsed <= 3) {
		elapsed = glfwGetTime() - time;
		printf("%f\n", elapsed);
		glClearColor(0.2, 0.1, 0.2, 1.0);
		glfwPollEvents();
	}
	
    return 4;
}







	


	// glfwDestroyWindow(window);
	// glfwTerminate();