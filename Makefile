CC = g++
# CFLAGS = -Wall -g
GL_FLAGS = -lglew32 -lglu32 -lopengl32 -lglfw3

SRC_DIR = src

SOURCE = $(wildcard $(SRC_DIR)/*.cpp)
SOURCE := $(filter-out $(SRC_DIR)/main.cpp, $(SOURCE))
OBJECT = $(patsubst $(SRC_DIR)/%.cpp,./%.o,$(SOURCE))

PixelForce: main.o $(OBJECT) Makefile
	$(CC) -o PixelForce main.o $(OBJECT) $(GL_FLAGS)
$(OBJECT): $(SOURCE) Makefile
	$(CC) -c $(SOURCE) $(GL_FLAGS) 
main.o: main.cpp Makefile
	$(CC) -c main.cpp $(GL_FLAGS)
clean:
	del *.o*