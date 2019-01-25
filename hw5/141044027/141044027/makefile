all: main

main: compile link work
	
	
compile: 
	g++ -c main.cpp -std=c++11
	g++ -c Cell.cpp -std=c++11
	g++ -c ConnectFourAbstract.cpp -std=c++11
	g++ -c ConnectFourPlus.cpp -std=c++11
	g++ -c ConnectFourDiag.cpp -std=c++11
	g++ -c ConnectFourPlusUndo.cpp -std=c++11
	
link: 
	g++ main.o Cell.o ConnectFourAbstract.o ConnectFourDiag.o ConnectFourPlus.o ConnectFourPlusUndo.o -o homework5 -std=c++11

work:
	./homework5 < r1
	
clean:
	rm *.o homework5

