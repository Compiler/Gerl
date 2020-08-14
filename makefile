CXX = gcc
CXXFLAGS = -Wall -w -g

OUT_DIR = bin
LAUNCHER_NAME = Gerl
SRC_DIR = src
ENTRY_POINT = $(SRC_DIR)/main.c

GLAD_ROOT = outsourced/glad/
GLAD_INC = $(GLAD_ROOT)include
GLAD_SRC = $(GLAD_ROOT)src

GLFW_ROOT = outsourced/glfw-3.3.2/MinGWmingw32/
GLFW_INC = $(GLFW_ROOT)include
GLFW_LIB = $(GLFW_ROOT)lib
GLFW_SRC = $(GLFW_ROOT)../src

INC_INTERNAL = -I $(SRC_DIR)
INC=-I $(SRC_DIR)/ -I $(GLAD_INC) -I $(GLFW_INC)
LIBS = -L $(GLFW_LIB)
LINKS = -lglfw3 -lglu32 -lopengl32 -lgdi32

OBJS = textloader.o vec3.o ray.o ArrayList.o PPMWriter.o
OUT_OBJECTS = $(patsubst %.o, $(OUT_DIR)/%.o, $(OBJS))



all: main

main: $(ENTRY_POINT) $(OBJS)
	$(CXX) $(CXXFLAGS) $(LIBS) $(INC) -o $(OUT_DIR)/$(LAUNCHER_NAME) $(OUT_OBJECTS)  $(ENTRY_POINT) $(GLAD_SRC)/glad.c $(LINKS)

run: $(OUT_DIR)/$(LAUNCHER_NAME).exe
	./$(OUT_DIR)/$(LAUNCHER_NAME).exe



textloader.o: $(SRC_DIR)/Assets/TextLoader.c
	$(CXX) $(CXXFLAGS) $(INC_INTERNAL) -c $(SRC_DIR)/Assets/TextLoader.c -o $(OUT_DIR)/TextLoader.o

vec3.o: $(SRC_DIR)/Math/Vec3.c
	$(CXX) $(CXXFLAGS) $(INC_INTERNAL) -c $(SRC_DIR)/Math/Vec3.c -o $(OUT_DIR)/vec3.o

ray.o: $(SRC_DIR)/Math/Ray.c 
	$(CXX) $(CXXFLAGS) $(INC_INTERNAL) -c $(SRC_DIR)/Math/Ray.c -o $(OUT_DIR)/ray.o 

ArrayList.o: $(SRC_DIR)/GerlLib/ArrayList.c
	$(CXX) $(CXXFLAGS) $(INC_INTERNAL) -c $(SRC_DIR)/GerlLib/ArrayList.c -o $(OUT_DIR)/ArrayList.o 

PPMWriter.o: $(SRC_DIR)/Assets/PPMWriter.c
	$(CXX) $(CXXFLAGS) $(INC_INTERNAL) -c $(SRC_DIR)/Assets/PPMWriter.c -o $(OUT_DIR)/PPMWriter.o 




clean:
	cd $(OUT_DIR)
	rm -f Gerl.exe