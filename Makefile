INCLUDE_PATH = -IC:\msys64\mingw64\include\SDL2
LIBS_PATH = -LC:\msys64\mingw64\lib
LIBS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -I include
FLAGS = -w -Wl,-subsystem,windows

SDL = $(INCLUDE_PATH) $(LIBS_PATH) $(FLAGS) $(LIBS)

all : PongGame

PongGame : src/main.cpp include/*.hpp
	g++ $< $(SDL) -o bin/$@

run : PongGame
	./bin/$<