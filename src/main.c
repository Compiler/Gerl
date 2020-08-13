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
	ArrayList* list = ArrayList_create(sizeof(ray));
	ray* rayPointer = malloc(sizeof(ray));
	ray_setPosition(rayPointer, 0, 8, 0);
	ray_setDirection(rayPointer, 0, 1, -1);

	ray rayStack;
	ray_setPosition(&rayStack, 1, 2, 3);
	ray_setDirection(&rayStack, 1, 0, 0);

	GERL_LOG("rayStack.position = (%f, %f, %f) \t rayStack.direction = (%f, %f, %f) \n", rayStack.position.x, rayStack.position.y, rayStack.position.z, rayStack.direction.x, rayStack.direction.y, rayStack.direction.z);
	GERL_LOG("rayPointer.position = (%f, %f, %f) \t rayPointer.direction = (%f, %f, %f) \n", rayPointer->position.x, rayPointer->position.y, rayPointer->position.z, rayPointer->direction.x, rayPointer->direction.y, rayPointer->direction.z);
	ArrayList_add(list, (void*)rayPointer);
	GERL_LOG("Added\n");
	((ray*)ArrayList_get(list, 0))->position.x = 3;
	rayStack = *(ray*)ArrayList_get(list, 0);
	GERL_LOG("rayStack.position = (%f, %f, %f) \t rayStack.direction = (%f, %f, %f) \n", rayStack.position.x, rayStack.position.y, rayStack.position.z, rayStack.direction.x, rayStack.direction.y, rayStack.direction.z);
	GERL_LOG("rayPointer.position = (%f, %f, %f) \t rayPointer.direction = (%f, %f, %f) \n", rayPointer->position.x, rayPointer->position.y, rayPointer->position.z, rayPointer->direction.x, rayPointer->direction.y, rayPointer->direction.z);
	





	 // Image

    const int image_width = 256;
    const int image_height = 256;

    // Render

    printf("P3\n%d %d\n255\n", image_width, image_height);
	const char buf[4096];
	uint16_t place = 0;
	FILE *fp;

    fp = fopen("test.ppm", "w+");
	fprintf(fp, "P3\n%d %d\n255\n", image_width, image_height);
    for (int j = image_height-1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {
			double ii = i;
			double jj = j;
            double r = ii / (image_width-1);
            double g = jj / (image_height-1);
            double b = 0.25;

            int ir = (int)(255.999 * r);
            int ig = (int)(255.999 * g);
            int ib = (int)(255.999 * b);
            printf("%d %d %d\n", ir, ig, ib);
			fprintf(fp, "%d %d %d\n", ir, ig, ib);
        }
    }




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







	


	