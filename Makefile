CXXFLAGS=-Wall -Wextra -O0 -g -std=c++11

main: main.o Node.o Operator.o Leaf.o Operation.o
	g++ main.o Node.o Operator.o Leaf.o Operation.o -o main

main.o: main.cpp Node.h Operator.h Leaf.h Operation.h
	g++ -o main.o -c ${CXXFLAGS} main.cpp

Generation.o: Generation.cpp Generation.h
	g++ -o Generation.o -c ${CXXFLAGS} Generation.cpp

Tree.o: Tree.cpp Tree.h
	g++ -o Tree.o -c ${CXXFLAGS} Tree.cpp

Node.o: Node.cpp Node.h
	g++ -o Node.o -c ${CXXFLAGS} Node.cpp

Operator.o: Operator.cpp Operator.h
	g++ -o Operator.o -c ${CXXFLAGS} Operator.cpp

Leaf.o: Leaf.cpp Leaf.h
	g++ -o Leaf.o -c ${CXXFLAGS} Leaf.cpp

Operation.o: Operation.cpp Operation.h
	g++ -o Operation.o -c ${CXXFLAGS} Operation.cpp

clean: 
	rm main main.o Generation.o Tree.o Node.o Operator.o Leaf.o Operation.o
