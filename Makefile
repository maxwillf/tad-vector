# Makefile for the Basic Structure Data I Projet "TAD-VECTOR"
#
# Made by Max William, minor changes by Felipe Ramos

# Default Conventions
Target = vector 	# Name of the project
INCLUDES = include
HEADERS = $(wildcard $(INCLUDES)/*)
CXX = g++
CXXFLAGS = -std=c++11 -g -ggdb -I $(INCLUDES)
DOCS = html latex

# Directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Some locations
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)


all: project #docs

project: $(OBJECTS) $(HEADERS) | $(BINDIR)
	@echo "Linking files:" $(OBJECTS) 
	@$(CXX) $(OBJECTS) $(CXXFLAGS) -o $(BINDIR)/$(Target)
	@ln -sfv $(BINDIR)/$(Target) $(Target) # Creates a link to the root folder

docs: 
	@echo "Generating documentation"
	@doxygen Doxyfile
	
$(OBJECTS):	$(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(HEADERS) | $(OBJDIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Sources: $<" 
	@echo "Compiling files {$<} to {$@}"
	@echo "Compiled {$<} succesfully!"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(BINDIR):
	@mkdir -p $(BINDIR)

# PHONY targets
.PHONY: clean clean_txt clean_docs clean_proj

clean: clean_proj #clean_txt clean_docs

clean_proj:
	@rm -r $(OBJDIR)			# Removes all objects on $(OBJDIR)
	@rm -rf $(BINDIR)/*			# Removes the binary file
	@rm $(Target)				# Removes the symlink
	@echo "Cleanup done!"		# Simple debug text
clean_txt: $(TEXT)
	@rm -f $(TEXT)				# Removes all TXT files

clean_docs: $(DOCS)
	@rm -r $(DOCS)				# Removes all Doc generated files
