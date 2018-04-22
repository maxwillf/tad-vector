Target = vector
INCLUDES = include
HEADERS = $(wildcard $(INCLUDES)/*)
CXX = g++
CXXFLAGS = -std=c++11 -g -ggdb -I $(INCLUDES)
DOCS = html latex
SRCDIR = src
OBJDIR = obj

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: project #docs
project: $(OBJECTS) $(HEADERS)
	@echo "Linkin Files: " $(OBJECTS) 
	@$(CXX) $(OBJECTS) $(CXXFLAGS) -o $(Target)
	@echo "Linkin complete!"

docs: 
	@echo "Generating Documentation"
	@doxygen Doxyfile
	
$(OBJECTS):	$(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(HEADERS) | $(OBJDIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Sources $<" 
	@echo "Compiling Files $< to  $@ "
	@echo "Compiled "$<" Succesfully!"

$(OBJDIR):
	mkdir -p $(OBJDIR)

.PHONY: clean clean_txt clean_docs clean_proj
clean: clean_proj #clean_txt clean_docs

clean_proj:
	@rm -r $(OBJDIR)
	@rm $(Target)
	@echo "Cleanup Complete!"
clean_txt: $(TEXT)
	@rm -f $(TEXT)

clean_docs: $(DOCS)
	@rm -r $(DOCS)
