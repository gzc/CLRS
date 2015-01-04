sample : main.o p_queue.o
	g++ -o sample main.o p_queue.o
main.o : main.cpp p_queue.h
	g++ -c main.cpp
p_queue.o : p_queue.h p_queue.cpp
	g++ -c p_queue.cpp

clean :
	rm sample main.o p_queue.o
