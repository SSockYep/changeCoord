all: main main2

main2: CalcCoord.o main2.cpp
	g++ -o main2 CalcCoord.o main2.cpp

main: CalcCoord.o main.cpp
	g++ -o main CalcCoord.o main.cpp

CalcCoord.o: CalcCoord.cpp
	g++ -c CalcCoord.cpp

clean:
	rm *.o main main2
