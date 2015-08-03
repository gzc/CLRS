main : huffman_test_client.o HUFFMAN.o BinaryStdIn.o BinaryStdOut.o
		g++ -o main huffman_test_client.o HUFFMAN.o BinaryStdIn.o BinaryStdOut.o
huffman_test_client.o : huffman_test_client.cpp ../HUFFMAN.h
		g++ -c huffman_test_client.cpp
HUFFMAN.o : ../HUFFMAN.h ../HUFFMAN.cpp ../BinaryStdIn.h ../BinaryStdOut.h
		g++ -c -DDEBUG=1 ../HUFFMAN.cpp
BinaryStdIn.o : ../BinaryStdIn.h ../BinaryStdIn.cpp
		g++ -c ../BinaryStdIn.cpp
BinaryStdOut.o : ../BinaryStdOut.h ../BinaryStdOut.cpp
		g++ -c ../BinaryStdOut.cpp

clean :
		rm main huffman_test_client.o HUFFMAN.o BinaryStdOut.o BinaryStdIn.o
