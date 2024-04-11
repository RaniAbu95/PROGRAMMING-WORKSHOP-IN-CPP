CPPC = g++
FLAGS = -Wall -Wextra -Wvla -std=c++17 -pthread -g

all: TimeChecker
	./TimeChecker 500

Matrix: Matrix.hpp
	$(CPPC) $(FLAGS) $^ -c

TimeChecker: TimeChecker.o Complex.o
	$(CPPC)  -g $^ -o $@

Complex.o: Complex.cpp Complex.h
	$(CPPC) $(FLAGS) Complex.cpp -c

TimeChecker.o: TimeChecker.cpp Matrix.hpp
	$(CPPC) $(FLAGS) -I /usr/include/eigen3/ TimeChecker.cpp -c

clean:
	rm -rf *.o Matrix.hpp.gch TimeChecker

tar: 
	tar -cvf ex3.tar Matrix.hpp MatrixException.cpp TimeChecker.cpp Makefile README extension.pdf

.PHONY: all clean
