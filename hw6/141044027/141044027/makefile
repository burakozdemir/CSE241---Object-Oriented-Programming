all: main

main: compile link work
	
	
compile: 
	g++ -c main.cpp -std=c++11
	g++ -c GTUSetBase.cpp -std=c++11
	g++ -c GTUSet.cpp -std=c++11
	g++ -c GTUMap.cpp -std=c++11
	
link: 
	g++ main.o GTUSetBase.o GTUSet.o GTUMap.o -o homework6 -std=c++11

work:
	./homework6 
	
clean:
	rm *.o homework6

