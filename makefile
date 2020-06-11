CXX = gcc

INC=-I src/ -I outsourced/glad/include/ -I outsourced/glfw-3.3.2/MinGWmingw32/include/
LIBS = -L outsourced/glfw-3.3.2/MinGWmingw32/lib/

all: main

main: src/main.c
	$(CXX) $(LIBS) $(INC) -o bin/Gerl src/main.c -lglfw3 -lopengl32 -lglu32 -lgdi32

run: bin/Gerl.exe
	./bin/Gerl.exe