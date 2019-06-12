#*******************************************
#** Program Name: Project2
#** Author: Brandon Mai
#** Date: 4/14/2019
#******************************************

#Template Adapted from Makefile help from class module 

output: main.o animal.o penguin.o tiger.o turtle.o zoo.o
	g++ main.o animal.o penguin.o tiger.o turtle.o zoo.o -o output

main.o: main.cpp
	g++ -c main.cpp

animal.o: animal.cpp animal.hpp
	g++ -c animal.cpp

penguin.o: penguin.cpp penguin.hpp
	g++ -c penguin.cpp

tiger.o: tiger.cpp tiger.hpp
	g++ -c tiger.cpp

turtle.o: turtle.cpp turtle.hpp
	g++ -c turtle.cpp

zoo.o: zoo.cpp zoo.hpp
	g++ -c zoo.cpp

Target: dependencies
	action

clean:
	rm *.o output
