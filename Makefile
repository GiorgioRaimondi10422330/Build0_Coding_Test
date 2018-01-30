CXX = g++
CPPFLAGS= -I.
CXXFLAGS= -std=c++11

SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)
LIBHEADERS=$(wildcard *.hpp)
EXEC= runnable

.PHONY: all compile run clean 

all:
	@echo "------------------------ HELP -------------------------------"
	@echo 
	@echo "make compile : to compile the program and generate the executable" 
	@echo "make run     : to compile and run the executable"
	@echo "make clean   : to delete objects and executable"
	@echo


compile: $(EXEC)
	@echo 
	@echo "Program API compiled"
	@echo

main.o: main.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o main.o -c main.cpp

API.o: API.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o API.o -c API.cpp

$(EXEC): $(OBJS)
	$(CXX) -o $@ $(OBJS)

clean:
	$(RM) $(OBJS) $(EXEC) *~ *.log

run: $(EXEC)
	./$(EXEC)
