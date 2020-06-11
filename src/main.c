#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <Core/GerlCore.h>
#include <Logger/GerlLogger.h>

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

	float time = glfwGetTime();
	float elapsed = glfwGetTime() - time;
	printf("%f\n", elapsed);
	while(!glfwWindowShouldClose(window)) {
		elapsed = glfwGetTime() - time;
		//printf("\033[1;31m %f\n", elapsed);
		GERL_LOG("Hello\n");
		GERL_DEBUG("Hello\n");
		GERL_WARN("Hello\n");
		GERL_ERROR("Hello\n");
		GERL_FATAL("Hello\n");
		glClearColor(0.2, 0.1, 0.2, 1.0);
		glfwPollEvents();
	}
	
	printf("\033[0m \n"); //reset logger

    return 4;
}







	


	// glfwDestroyWindow(window);
	// glfwTerminate();