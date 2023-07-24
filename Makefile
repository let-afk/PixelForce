CC = g++
CFLAGLIB = -lglew32 -lglu32 -lopengl32 -lglfw3

PixelForce: main.o window.o Makefile
	$(CC) -o PixelForce main.o window.o $(CFLAGLIB)
window.o: window.cpp Makefile
	$(CC) -c window.cpp $(CFLAGLIB)
main.o: main.cpp Makefile
	$(CC) -c main.cpp $(CFLAGLIB)

