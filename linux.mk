CC := gcc
CPP := g++
CFLAGS := -Wall -g `sdl2-config --cflags` -std=c11
CPPFLAGS := -Wall -g `sdl2-config --cflags` -std=c++11
LFLAGS := `sdl2-config --libs` -lm -lSDL2_image

OBJ := obj/linux/
BIN := bin/linux/

TARGET := $(BIN)SuperGuy

SRCDIRS := src src/* src/*/* src/*/*/*
SOURCES := $(foreach DIR, $(SRCDIRS), $(wildcard $(DIR)/*.c)) $(foreach DIR, $(SRCDIRS), $(wildcard $(DIR)/*.cpp))
OBJECTS = $(patsubst %.cpp, $(OBJ)%.o, $(patsubst %.c, $(OBJ)%.o, $(SOURCES)))

.PHONY: all todo

all: $(TARGET)
	cp -r resources/* $(BIN)

$(OBJ)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@	

$(OBJ)%.o: %.cpp
	mkdir -p $(dir $@)
	$(CPP) $(CPPFLAGS) -c $< -o $@	

$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN)
	$(CPP) $(LFLAGS) $^ -o $@
	
todo:
	-@for file in $(SOURCES); do fgrep -H -e TODO -e FIXME $$file; done; true
