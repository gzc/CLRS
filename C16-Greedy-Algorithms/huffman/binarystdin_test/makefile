test_BinaryStdIn : main.o BinaryStdIn.o
		g++ -o test_BinaryStdIn main.o BinaryStdIn.o 
main.o : main.cpp ../BinaryStdIn.h
		g++ -c main.cpp
BinaryStdIn.o : ../BinaryStdIn.h ../BinaryStdIn.cpp
		g++ -c -DDEBUG=1 ../BinaryStdIn.cpp

clean :
		rm test_BinaryStdIn main.o BinaryStdIn.o
