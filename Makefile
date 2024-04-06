# Input files
OBJS = src/main.cpp \
	   $(wildcard src/lib/*.cpp) \
	   $(wildcard src/lib/tools/*.cpp) \
	   $(wildcard src/lib/http/*.cpp)

# Output file
OBJ = bin/alpha_webserver

# Compiler flags
COMPILER_FLAGS = -w

# Linker flags
#LINKER_FLAGS = -lSDL2

# Compiler
CC = g++


all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) -o $(OBJ) 
