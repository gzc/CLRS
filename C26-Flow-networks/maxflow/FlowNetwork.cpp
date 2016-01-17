/*************************************************************************
	> File Name: FlowNetwork.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Fri Nov 13 08:43:38 2015
 ************************************************************************/

#ifndef Flow_Network_H
#define Flow_Network_H

#include<iostream>
#include<fstream>
#include<vector>
#include<list>
#include "FlowEdge.cpp"

using namespace std;

class FlowNetwork {
    
    int V;
    int E;
    vector<list<FlowEdge> > adj;

public:
    
    FlowNetwork(int V) {
        this->V = V;
        this->E = 0;
        for (int v = 0; v < V; v++) {
            list<FlowEdge> temp;
            adj.push_back(temp);
        }
    }

    FlowNetwork(ifstream& in) {
        int k, e;
        in >> k;
        new(this) FlowNetwork(k);
        in >> e;

        for (int i = 0; i < e; i++) {
            int v,w;
            in >> v;
            in >> w;
            double capacity;
            in >> capacity;
            FlowEdge fe(v, w, capacity);
            addEdge(fe);
        }
    }

    int getV() {
        return this->V;
    }

    int getE() {
        return this->E;
    }
    
    void addEdge(FlowEdge e) {
        int v = e.from();
        int w = e.to();
        adj[v].push_back(e);
        adj[w].push_back(e);
        this->E++;
    }
    
    list<FlowEdge> getadj(int v) {
        return adj[v];
    }
    
    void addResidualFlowTo(FlowEdge e, int v, double bottle) {
        for(list<FlowEdge>::iterator it = adj[e.from()].begin(); it != adj[e.from()].end(); it++) {
            if(it->from() == e.from() && it->to() == e.to()) {
                it->addResidualFlowTo(v, bottle);
                break;
            }
        }
    }
    
    list<FlowEdge> edges() {
        list<FlowEdge> lists;
        for (int v = 0; v < this->V; v++)
            for (FlowEdge e : getadj(v)) {
                if (e.to() != v)
                    lists.push_back(e);
            }
        return lists;
    }
    
    friend ostream& operator << (ostream& out, FlowNetwork& fn)
    {
        out << to_string(fn.V) << " " << to_string(fn.E) << endl;
        for (int v = 0; v < fn.V; v++) {
            out << to_string(v) << ":  ";
            for (FlowEdge e : fn.getadj(v)) {
                if (e.to() != v) out << e << "  ";
            }
            out << endl;
        }
        return out;
    }
};

#endif