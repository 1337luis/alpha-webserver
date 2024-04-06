# Input files
OBJS = src/main.cpp \
	   src/lib/Logger.cpp


# Output file
OBJ = bin/main

# Compiler flags
COMPILER_FLAGS = -w

# Linker flags
#LINKER_FLAGS = -lSDL2

# Compiler
CC = g++


all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) -o $(OBJ) 
