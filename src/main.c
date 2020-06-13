#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <Core/GerlCore.h>
#include <Logger/GerlLogger.h>
#include <Assets/TextLoader.h>

int main(){


	if(!glfwInit()) printf("Failed to init glfw");
	

	char* vert = getTextContents("src/Resources/Shaders/pass.vert");
	printf("%s", vert);
	GERL_FATAL("ERROR\n");
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
	GERL_LOG("POG CHAMP");


	float a = 0.75f;
	float vertices[7 * 3] = {
		-a, -a, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		-a,  a, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		 a, -a, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f };
	
	unsigned int bufferID, arrayID;
	glGenBuffers(1, &bufferID);

	glGenVertexArrays(1, arrayID);
	glBindVertexArray(arrayID);


	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(float), NULL, GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (const GLvoid*)0);///xyz
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (const GLvoid*)(3 * sizeof(GLfloat)));

	while(!glfwWindowShouldClose(window)) {
		elapsed = glfwGetTime() - time;

		glClearColor(0.2, 0.1, 0.2, 1.0);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwPollEvents();
	}
	
	printf("\033[0m \n"); //reset logger



	glfwDestroyWindow(window);
	glfwTerminate();

    return 4;
}







	


	