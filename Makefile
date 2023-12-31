
# https://www.cs.colostate.edu/~cs157/LectureMakefile.pdf

CXX= g++
CXXFLAGS= -std=c++17
OBJFILES= bin/main.o bin/licence.o
TARGET= bin/colors


all: $(TARGET)


install: all
	cp $(TARGET) /usr/bin/

$(TARGET): bin $(OBJFILES)
	@echo FINAL BINARY:
	$(CXX) $(CXXFLAGS) $(OBJFILES) -o $(TARGET)
	
bin:
	mkdir bin

bin/main.o: src/main.cxx
	@echo MAIN CPP:
	$(CXX) $(CXXFLAGS) src/main.cxx -c -o bin/main.o

bin/licence.o: src/licence.cxx
	@echo LICENCE:
	$(CXX) $(CXXFLAGS) src/licence.cxx -c -o bin/licence.o
	

clean:
	rm -f bin/*


.PHONY: clean install all



