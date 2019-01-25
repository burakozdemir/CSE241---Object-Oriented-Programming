all: main

main: compile link work
	
	
compile: 
	g++ -c main.cpp -std=c++11
	g++ -c ConnectFour.cpp -std=c++11
	
link: 
	g++ main.o ConnectFour.o -o homework3 -std=c++11

work:
	./homework3
	
clean:
	rm *.o homework3
	
	
