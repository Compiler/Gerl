#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <Core/GerlCore.h>
#include <Logger/GerlLogger.h>
#include <Assets/TextLoader.h>
#include <Math/Vec3.h>
#include <Math/Ray.h>
#include <GerlLib/ArrayList.h>

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
int testing(){
	ArrayList* list = ArrayList_create();
	ray* ray1 = malloc(sizeof(ray));
	ray1->position.x = 1;ray1->position.y = 2;ray1->position.z = 3;
	ray1->direction.x = 4;ray1->direction.y = 5;ray1->direction.z = 6;


	ray r1;
	r1.position.x = 0;r1.position.y = 0;r1.position.z = 0;
	r1.direction.x = 1;r1.direction.y = 0;r1.direction.z = 0;
	ray1 = &r1;
	ArrayList_add(list, ray1);
	GERL_LOG("ray position = (%f, %f, %f) \n", r1.position.x, r1.position.y, r1.position.z);
	r1 = *(ray*)ArrayList_get(list, 0);
	GERL_LOG("ray position = (%f, %f, %f) \n", r1.position.x, r1.position.y, r1.position.z);



	GERL_WARN("Finished");
	printf("\033[0m \n"); //reset logger

	return 0;

}
int main(){
	return testing();
	/*if(!glfwInit()) printf("Failed to init glfw");
	vec3 a, b;
	a.x = 5.0f; a.y = 5.0f; a.z = 5.0f;
	b.x = 4.0f; b.y = 4.0f; b.z = 4.0f;

	GERL_LOG("a = (%f, %f, %f) \t b = (%f, %f, %f)\n", a.x, a.y, a.z, b.x, b.y, b.z,);

	vec3_mulValTo(&a, 4);
	GERL_LOG("a = (%f, %f, %f) \t b = (%f, %f, %f)\n", a.x, a.y, a.z, b.x, b.y, b.z,);

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

	
	int index = 0;

	initShader(GERL_INTERNAL_SHADERS("pass.vert"), GERL_INTERNAL_SHADERS("RayMarching.frag"));
	glUseProgram(shaderProgram);

	float sz = 0.75f;
	float vertices[7 * 6] = {
		-sz, -sz, 0.0f, 	1.0f, 1.0f, 1.0f, 1.0f, // bottom left
		-sz,  sz, 0.0f,	1.0f, 1.0f, 1.0f, 1.0f, // top left
		 sz, -sz, 0.0f, 	1.0f, 1.0f, 1.0f, 1.0f, // bottom right

		 sz,  sz, 0.0f, 	0.0f, 1.0f, 1.0f, 1.0f, //top right
		-sz,  sz, 0.0f,	0.0f, 1.0f, 1.0f, 1.0f,
		 sz, -sz, 0.0f, 	0.0f, 1.0f, 1.0f, 1.0f	 };
	
	unsigned int bufferID, arrayID;
	glGenVertexArrays(1, &arrayID);
	glBindVertexArray(arrayID);
	
	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (const void*)0);///xyz
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (const void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	int el = 0;
	//!glfwWindowShouldClose(window)
	int frames = 0;
	int prevFrames = 0;
	double startFrameTime = glfwGetTime();
	double lastFrameTime = glfwGetTime();
	double deltaTime = lastFrameTime - startFrameTime;
	double elapsedTime = deltaTime;
	while(!glfwWindowShouldClose(window)) {
		startFrameTime = glfwGetTime();
		deltaTime = startFrameTime - lastFrameTime;
		lastFrameTime = startFrameTime;
		elapsedTime += deltaTime;
		if(elapsedTime >= 1.0){
			GERL_DEBUG("\t\tFPS: %d\t\tms: %f\n", frames, deltaTime, );
			elapsedTime = 0;
			frames = 0;
		}
		
		glClearColor(0.2, 0.1, 0.2, 1.0);
		glUseProgram(shaderProgram);
		glBindVertexArray(arrayID);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glfwPollEvents();
		glfwSwapBuffers(window);
		frames++;
	}
	
	GERL_LOG("Finished");
	printf("\033[0m \n"); //reset logger

	glfwDestroyWindow(window);
	glfwTerminate();*/

   // return 4;
}







	


	