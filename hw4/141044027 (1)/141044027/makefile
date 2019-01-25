all: main

main: compile link work
	
	
compile: 
	g++ -c main.cpp -std=c++11
	g++ -c ConnectFour.cpp -std=c++11
	
link: 
	g++ main.o ConnectFour.o -o homework4 -std=c++11

work:
	./homework4 < r5
	
clean:
	rm *.o homework4
	
	
