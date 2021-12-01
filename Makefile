# Executable names:
EXE = main
TEST = test

# Add all object files needed for compiling:
EXE_OBJ = main.o
OBJS = main.o read.o graph.o functions.o draw.o

# Generated files
#CLEAN_RM = unsolved.png solved.png testdsets testsquaremaze \
						*.o *.d tests/*.o tests/*.d cs225/*.d cs225/*.o \
						cs225/lodepng/*.o cs225/lodepng/*.d \
						cs225/catch/*.o cs225/catch/*.d

# Use the cs225 makefile template:
include cs225/make/cs225.mk
