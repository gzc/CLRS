test_BinaryStdOut : main.o BinaryStdOut.o
		g++ -o test_BinaryStdOut main.o BinaryStdOut.o 
main.o : main.cpp ../BinaryStdOut.h
		g++ -c main.cpp
BinaryStdOut.o : ../BinaryStdOut.h ../BinaryStdOut.cpp
		g++ -c -DDEBUG=1 ../BinaryStdOut.cpp

clean :
		rm test_BinaryStdOut main.o BinaryStdOut.o
