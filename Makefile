CC = g++
SOURCE = window.cpp shader.cpp
#HEADER = $(SOURCE:.cpp=.h)
OBJECT = $(SOURCE:.cpp=.o)
#FLAGS = 
GL_FLAGS = -lglew32 -lglu32 -lopengl32 -lglfw3

PixelForce: main.o $(OBJECT) Makefile
	$(CC) -o PixelForce main.o $(OBJECT) $(GL_FLAGS)
$(OBJECT): $(SOURCE) Makefile
	$(CC) -c $(SOURCE) $(GL_FLAGS)
main.o: main.cpp Makefile
	$(CC) -c main.cpp $(GL_FLAGS)
#не рекомендую
clean:
	del *.o*