# Makefile for the BDSI project "TAD-VECTOR"

# Creator:
# 	- Felipe Ramos

# Makefile conventions
SHELL = /bin/sh

# Directories
incdir = ./include
srcdir = ./src
objdir = ./obj
bindir = ./bin
# datadir = ./data

# Macros
CC = g++
CFLAGS = -Wall -g -ggdb -std=c++11 -I. -I$(incdir)
RM = -rm
OBJS = $(addprefix $(objdir)/,vector.o)

# Phony targets
.PHONY: clean cleanobj cleanbin cleansym
.PHONY: all run main build vector

# Use "make" to execute everything
all: build main

# Use "make run" to compile and execute everything
run: build main tad-vector

# Use "make main" to compile the main
main: tad-vector

# Use "make build" to build all the modules
build: vector

# Use "make <name>" to build only the <name> module
vector: $(objdir)/vector.o

# Compiles the main
tad-vector: $(srcdir)/main.cpp $(OBJS)
	@mkdir -p $(bindir)
	@$(CC) $(CFLAGS) $^ -o $(bindir)/$@
	@ln -sFv $(bindir)/$@ $@
	@echo "Symlink created with sucess! To execute just type ./$@\n\n"


# Builds only the vector module
$(objdir)/vector.o: $(srcdir)/vector.cpp $(incdir)/vector.hpp
	mkdir -p $(objdir)
	$(CC) $(CFLAGS) -c $< -o $@

# Removes all objects
cleanobj:
	$(RM) $(objdir)/*.o

# Clean all executables
cleanbin:
	$(RM) -rf $(bindir)/*

cleansym:
	$(RM) -rf tad-vector

clean: cleanobj cleanbin cleansym
