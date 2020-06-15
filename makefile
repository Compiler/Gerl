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


INC=-I $(SRC_DIR)/ -I $(GLAD_INC) -I $(GLFW_INC)
LIBS = -L $(GLFW_LIB)
LINKS = -lglfw3 -lglu32 -lopengl32 -lgdi32

all: main

main: $(ENTRY_POINT) textloader.o
	$(CXX) $(CXXFLAGS) $(LIBS) $(INC) -o $(OUT_DIR)/$(LAUNCHER_NAME) $(OUT_DIR)/TextLoader.o $(ENTRY_POINT) $(GLAD_SRC)/glad.c $(LINKS)

run: $(OUT_DIR)/$(LAUNCHER_NAME).exe
	./$(OUT_DIR)/$(LAUNCHER_NAME).exe


textloader.o: $(SRC_DIR)/Assets/TextLoader.c
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Assets/TextLoader.c -o $(OUT_DIR)/TextLoader.o

vec3.o: $(SRC_DIR)/Math/Vec3.c
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Math/Vec3.c -o $(OUT_DIR)/vec3.o




clean:
	cd $(OUT_DIR)
	rm -f Gerl.exe