CXX = g++
OBJECTS = ArenstorfPoint.o Arenstorf.o
FLAGS = -Wextra -Wall -Wvla -std=c++17 -pthread -g -DNDEBUG
TARFILES= Ex1.cpp Arenstorf.h Arenstorf.cpp ArenstorfPoint.h ArenstorfPoint.cpp graphs.pdf output1e3.txt output1e9.txt Makefile
TARGETS = Ex1.cpp Arenstorf.h Arenstorf.cpp ArenstorfPoint.h ArenstorfPoint.cpp
LC_F = --leak-check=full
SPL_Y = --show-possibly-lost=yes
SR_Y = --show-reachable=yes
UVE_Y = --undef-value-errors=yes

all: ex1

ex1: $(OBJECTS)
	$(CXX) $(FLAGS) -c Ex1.cpp -o Ex1.o
	$(CXX) $(FLAGS) $(OBJECTS) Ex1.o -o ex1

ArenstorfPoint.o: ArenstorfPoint.cpp ArenstorfPoint.h
	$(CXX) $(FLAGS) -c ArenstorfPoint.cpp

Arenstorf.o: Arenstorf.cpp Arenstorf.h Arenstorf.h
	$(CXX) $(FLAGS) -c Arenstorf.cpp 

tar:
	tar cvf ex1.tar $(TARFILES)

ArenstorfPoint: ArenstorfPoint.o
	$(CXX) $(FLAGS) ArenstorfPoint.o -o ArenstorfPoint

Arenstorf: Arenstorf.o
	$(CXX) $(FLAGS) Arenstorf.o -o Arenstorf

valdbg: ex1 input1e3.txt
	valgrind $(LC_F) $(SPL_Y) $(SR_Y) $(UVE_Y) ex1 input1e3.txt out_valgrind1.txt
	valgrind $(LC_F) $(SPL_Y) $(SR_Y) $(UVE_Y) ex1 out_valgrind2.txt

clean:
	rm -f *.o ex1
