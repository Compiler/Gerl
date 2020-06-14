#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <Core/GerlCore.h>
#include <Logger/GerlLogger.h>
#include <Assets/TextLoader.h>

void check(){
	static int callCount = 1;
	printf("Called %d times", callCount++);
	const GLenum err = glGetError();
	if (err == GL_NO_ERROR){
		GERL_LOG("NO error\n");
		fflush(stdout);
	}else{
		GERL_ERROR("Error\n");
		fflush(stdout);
	}
}

int main(){


	if(!glfwInit()) printf("Failed to init glfw");
	

	char* vert = getTextContents(GERL_INTERNAL_SHADERS("pass.vert"));
	char* frag = getTextContents("src/Resources/Shaders/pass.frag");
	//printf("Vertex: '%s'\n", vert);
	//printf("Fragment: '%s'\n", frag);
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
	GERL_LOG("POG CHAMP\n");
	int index = 0;
	printf("Here %d\n", index++);

	float a = 0.75f;
	float vertices[7 * 3] = {
		-a, -a, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		-a,  a, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		 a, -a, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f };
	
	printf("Here %d\n", index++);
	check();
	unsigned int bufferID, arrayID;
	printf("Here %d\n", index++);
	check();
	glGenVertexArrays(1, arrayID);
	check();
	printf("Here %d\n", index++);

	glBindVertexArray(arrayID);
	printf("Here %d\n", index++);
	check();
	

	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(float), NULL, GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (const GLvoid*)0);///xyz
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (const GLvoid*)(3 * sizeof(GLfloat)));
	int el = 0;
	//!glfwWindowShouldClose(window)
	while(1) {
		elapsed = glfwGetTime() - time;
		//printf("%d\n", el);
		glClearColor(0.2, 0.1, 0.2, 1.0);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwPollEvents();
	}
	
	GERL_LOG("Finished");
	printf("\033[0m \n"); //reset logger

	glfwDestroyWindow(window);
	glfwTerminate();

    return 4;
}







	


	