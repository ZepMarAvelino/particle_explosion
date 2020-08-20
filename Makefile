CXX       := g++
CXX_FLAGS := -std=c++11 -Wall -pthread -ggdb

BIN     := bin
SRC     := src
INCLUDE := -Iinclude -I/usr/include/SDL2/

LIBRARIES   := -lSDL2
EXECUTABLE  := main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) $(INCLUDE) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*