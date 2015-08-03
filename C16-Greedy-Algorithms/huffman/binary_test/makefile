main : main.o BinaryStdOut.o BinaryStdIn.o
		g++ -o main main.o BinaryStdOut.o BinaryStdIn.o
main.o : main.cpp ../BinaryStdOut.h ../BinaryStdIn.h
		g++ -c main.cpp
BinaryStdOut.o : ../BinaryStdOut.h ../BinaryStdOut.cpp
		g++ -c  ../BinaryStdOut.cpp
BinaryStdIn.o : ../BinaryStdIn.h ../BinaryStdIn.cpp
		g++ -c  ../BinaryStdIn.cpp

clean :
		rm main main.o BinaryStdOut.o BinaryStdIn.o
