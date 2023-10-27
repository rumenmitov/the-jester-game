#OBJS specifies which files to compile as part of the project
OBJS = src/*.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image

#OBJ_NAME specifies the name of our exectuable
DEBUG_OBJ_NAME = bin/debug/the-jester-game
PROD_OBJ_NAME = bin/release/the-jester-game

#This is the target that compiles our executable
debug : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(DEBUG_OBJ_NAME) -I include

prod : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(PROD_OBJ_NAME) -I include
