all: longmultiplication karatsuba
.PHONY:all
	
longmultiplication:	main.o
	g++ -o longmultiplication main.o; rm main.o
	
main.o : main.cpp
	g++ -c -O3  main.cpp

karatsuba: Karatsuba.o
	g++ -o karatsuba Karatsuba.o; rm Karatsuba.o

Karatsuba.o : Karatsuba.cpp
	g++ -c -O3 Karatsuba.cpp
