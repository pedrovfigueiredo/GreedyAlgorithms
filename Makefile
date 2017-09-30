SRC_DIR = Sources
OBJ_DIR = Object
CPPFLAGS  = -Wall -std=c++11
SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/vertex.cpp $(SRC_DIR)/graph.cpp $(SRC_DIR)/reader.cpp
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/vertex.o $(OBJ_DIR)/graph.o $(OBJ_DIR)/reader.o


all: build prim_djijkstra

prim_djijkstra: $(OBJS)
	g++ $(CPPFLAGS) $(OBJS) -o prim_djijkstra

build: $(OBJS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CPPFLAGS) -c $< -o $@


.PHONY: clean

clean:
	rm $(OBJS) prim_djijkstra
