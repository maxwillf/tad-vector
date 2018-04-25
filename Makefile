# Makefile for the Basic Structure Data I Projet "TAD-VECTOR"
#
# Made by Max William, minor changes by Felipe Ramos

# Conventions
Target = vector
INCLUDES = include
HEADERS = $(wildcard $(INCLUDES)/*)
CXX = g++
CXXFLAGS = -std=c++11 -g -ggdb -I $(INCLUDES)
DOCS = html latex
SRCDIR = src
OBJDIR = obj
BINDIR = bin

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: project #docs

project: $(OBJECTS) $(HEADERS) | $(BINDIR)
	@echo "> LINKIN FILES: " $(OBJECTS) 
	@$(CXX) $(OBJECTS) $(CXXFLAGS) -o $(BINDIR)/$(Target)
	@echo "> LINKIN COMPLETE!"
	@echo "Link created on:"
	@ln -sfv $(BINDIR)/$(Target) $(Target) # Creates a link to the root

docs: 
	@echo "> GENERATING DOCUMENTATION"
	@doxygen Doxyfile
	
$(OBJECTS):	$(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(HEADERS) | $(OBJDIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "> SOURCES $<" 
	@echo "> COMPILING FILES $< TO  $@ "
	@echo "> COMPILED "$<" SUCCESFULLY!"

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

.PHONY: clean clean_txt clean_docs clean_proj
clean: clean_proj #clean_txt clean_docs

clean_proj:
	@rm -r $(OBJDIR)
	@rm $(BINDIR)/$(Target)
	@rm $(Target)
	@echo "> CLEANUP DONE!"
clean_txt: $(TEXT)
	@rm -f $(TEXT)

clean_docs: $(DOCS)
	@rm -r $(DOCS)
