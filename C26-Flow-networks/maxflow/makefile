all: testnetwork testflowedge maxflow
.PHONY:all

maxflow: FordFulkerson.o
	g++ -o maxflow -std=c++11 FordFulkerson.o

FordFulkerson.o : FordFulkerson.cpp
	g++ -c -std=c++11 FordFulkerson.cpp

testnetwork:	testFlowNetwork.o FlowNetwork.o
	g++ -o testnetwork -std=c++11 testFlowNetwork.o FlowNetwork.o
	
testFlowNetwork.o : testFlowNetwork.cpp
	g++ -c -std=c++11 testFlowNetwork.cpp

FlowNetwork.o : FlowNetwork.cpp
	g++ -c -std=c++11 FlowNetwork.cpp
	
testflowedge: testFlowEdge.o FlowEdge.o
	g++ -o testflowedge testFlowEdge.o FlowEdge.o
	
testFlowEdge.o : testFlowEdge.cpp
	g++ -c testFlowEdge.cpp

FlowEdge.o : FlowEdge.cpp
	g++ -c FlowEdge.cpp

clean:
	rm testflowedge
	rm testFlowEdge.o
	rm FlowEdge.o
	rm testFlowNetwork.o
	rm FlowNetwork.o
	rm testnetwork
	rm FordFulkerson.o
	rm maxflow
