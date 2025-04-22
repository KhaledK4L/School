main: main.o sortCheck.o merge.o
	g++ -o main main.o sortCheck.o merge.o
main.o: main.cpp sortCheck.cpp merge.cpp sortCheck.h merge.h
	g++ -c main.cpp sortCheck.cpp merge.cpp
	