/*************************************************************************
	> File Name: FlowEdge.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Fri Nov 13 08:19:03 2015
 ************************************************************************/

#ifndef FLOW_EDGE_H
#define FLOW_EDGE_H

#include<iostream>
using namespace std;

class FlowEdge {
    int v;             // from
    int w;             // to
    double capacity;   // capacity
    double flow;       // flow
    
public:
    FlowEdge() {
        this->v         = -1;
        this->w         = -1;
        this->capacity  = 0;
        this->flow      = 0.0;
    }
    
    FlowEdge(int v, int w, double capacity) {
        this->v         = v;
        this->w         = w;
        this->capacity  = capacity;
        this->flow      = 0.0;
    }
    
    FlowEdge(int v, int w, double capacity, double flow) {
        this->v         = v;
        this->w         = w;
        this->capacity  = capacity;
        this->flow      = flow;
    }
    
    FlowEdge(const FlowEdge &e) {
        this->v         = e.v;
        this->w         = e.w;
        this->capacity  = e.capacity;
        this->flow      = e.flow;
    }
    
    int from() {
        return this->v;
    }
    
    int to() {
        return this->w;
    }
    
    double getCapacity() {
        return this->capacity;
    }
    
    double getFlow() {
        return this->flow;
    }
    
    int other(int vertex) {
        if  (vertex == v) return this->w;
        else return this->v;
    }
    
    double residualCapacityTo(int vertex) {
        if (vertex == this->v) return this->flow;  // backward edge
        else return this->capacity - this->flow;   // forward edge
    }
    
    void addResidualFlowTo(int vertex, double delta) {
        if (vertex == v) this->flow -= delta;     // backward edge
        else this->flow += delta;                 // forward edge
    }
    
    friend ostream& operator << (ostream& out, FlowEdge& fe)
    {
        out << to_string(fe.v) << "->" << to_string(fe.w) << "\t"
        << to_string(fe.flow) << "\t" << to_string(fe.capacity) << endl;
        return out;
    }
};

#endif