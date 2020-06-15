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

void checkShader(){

	
}

unsigned int shaderProgram = 0;
void initShader(const char* vertexFile, const char* fragmentFile){
	unsigned int vertexShader, fragmentShader;

	const char* vert = getTextContents(vertexFile);
	const char* frag = getTextContents(fragmentFile);

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vert, NULL);
	glCompileShader(vertexShader);
	{
		int  success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if(!success){
    		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    		printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\t %s", infoLog );
		}
	}
	

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &frag, NULL);
	glCompileShader(fragmentShader);

	{
		int  success;
		char infoLog[512];
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if(!success){
    		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    		printf("ERROR::SHADER::FRAG::COMPILATION_FAILED\t %s", infoLog );
		}
	}

	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	{
		int  success;
		char infoLog[512];
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if(!success) {
    		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    		printf("ERROR::SHADER::COMP::COMPILATION_FAILED\t %s", infoLog );
		}
	}

}

int main(){

	
	if(!glfwInit()) printf("Failed to init glfw");
	
	//char* vert = getTextContents(GERL_INTERNAL_SHADERS("pass.vert"));
	//char* frag = getTextContents("src/Resources/Shaders/pass.frag");
	//printf("Vertex: '%s'\n", vert);
	//printf("Fragment: '%s'\n", frag);
   	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);//version 4.6 Core profile
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	//glfwWindowHint(GLFW_SAMPLES, 4);
	GLFWwindow* window = glfwCreateWindow(640, 480, "C OPENGL", NULL, NULL);
	glfwMakeContextCurrent(window);
	if(!window){
		printf("Failed to load window");
	}
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Something went wrong!\n");
	}
	glViewport(0, 0, 640, 480);

	float time = glfwGetTime();
	float elapsed = glfwGetTime() - time;
	int index = 0;

	initShader(GERL_INTERNAL_SHADERS("pass.vert"), GERL_INTERNAL_SHADERS("pass.frag"));
	glUseProgram(shaderProgram);

	float a = 0.75f;
	float vertices[7 * 3] = {
		-a, -a, 0.0f, 	1.0f, 1.0f, 1.0f, 1.0f,
		-a,  a, 0.0f,	 1.0f, 1.0f, 1.0f, 1.0f,
		 a, -a, 0.0f, 	1.0f, 1.0f, 1.0f, 1.0f };
	
	unsigned int bufferID, arrayID;
	glGenVertexArrays(1, &arrayID);
	glBindVertexArray(arrayID);
	
	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	printf("%d, %d", sizeof(vertices), sizeof(float) * 18);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (const void*)0);///xyz
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (const void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	int el = 0;
	//!glfwWindowShouldClose(window)
	while(!glfwWindowShouldClose(window)) {
		elapsed = glfwGetTime() - time;
		glClearColor(0.2, 0.1, 0.2, 1.0);
		glUseProgram(shaderProgram);
		glBindVertexArray(arrayID);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	
	GERL_LOG("Finished");
	printf("\033[0m \n"); //reset logger

	glfwDestroyWindow(window);
	glfwTerminate();

    return 4;
}







	


	