/*************************************************************************
	> File Name: FordFulkerson.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Fri Nov 13 10:04:58 2015
 ************************************************************************/

#include<iostream>
#include<vector>
#include<cfloat>
#include<queue>
#include<cmath>
#include<fstream>
#include<cassert>
#include<algorithm>

#include "FlowNetwork.cpp"
#include "FlowEdge.cpp"

using namespace std;

/**
 *  Implementation with Edmonds-Karp
 */
class FordFulkerson {
    const double FLOATING_POINT_EPSILON = 1E-11;
    
    bool *marked;               // marked[v] = true iff s->v path in residual graph
    FlowEdge *edgeTo;           // edgeTo[v] = last edge on shortest residual s->v path
    double value;               // current value of max flow
    
    // return excess flow at vertex v
    double excess(FlowNetwork G, int v) {
        double excess = 0.0;
        for (FlowEdge e : G.getadj(v)) {
            if (v == e.from()) excess -= e.getFlow();
            else               excess += e.getFlow();
        }
        return excess;
    }
    
    // check optimality conditions
    bool check(FlowNetwork G, int s, int t) {
        
        // check that flow is feasible
        if (!isFeasible(G, s, t)) {
            cerr << "Flow is infeasible" << endl;
            return false;
        }
        
        // check that s is on the source side of min cut and that t is not on source side
        if (!inCut(s)) {
            cerr << "source " << s << " is not on source side of min cut" << endl;
            return false;
        }
        if (inCut(t)) {
            cerr << "sink " << t << " is on source side of min cut" << endl;
            return false;
        }
        
        // check that value of min cut = value of max flow
        double mincutValue = 0.0;
        for (int v = 0; v < G.getV(); v++) {
            for (FlowEdge e : G.getadj(v)) {
                if ((v == e.from()) && inCut(e.from()) && !inCut(e.to()))
                    mincutValue += e.getCapacity();
            }
        }
        
        if (abs(mincutValue - value) > FLOATING_POINT_EPSILON) {
            cerr << "Max flow value = " << value << ", min cut value = " << mincutValue << endl;
            return false;
        }
        
        return true;
    }
    
    // return excess flow at vertex v
    bool isFeasible(FlowNetwork G, int s, int t) {
        
        // check that capacity constraints are satisfied
        for (int v = 0; v < G.getV(); v++) {
            for (FlowEdge e : G.getadj(v)) {
                if (e.getFlow() < -FLOATING_POINT_EPSILON || e.getFlow() > e.getCapacity() + FLOATING_POINT_EPSILON) {
                    cerr << "Edge does not satisfy capacity constraints: " << e << endl;
                    return false;
                }
            }
        }
        
        // check that net flow into a vertex equals zero, except at source and sink
        if (abs(value + excess(G, s)) > FLOATING_POINT_EPSILON) {
            cerr << "Excess at source = " << excess(G, s) << endl;
            cerr << "Max flow         = " << value << endl;
            return false;
        }
        if (abs(value - excess(G, t)) > FLOATING_POINT_EPSILON) {
            cerr << "Excess at sink   = " << excess(G, t) << endl;
            cerr << "Max flow         = " << value << endl;
            return false;
        }
        for (int v = 0; v < G.getV(); v++) {
            if (v == s || v == t) continue;
            else if (abs(excess(G, v)) > FLOATING_POINT_EPSILON) {
                cerr << "Net flow out of " << v << " doesn't equal zero" << endl;
                return false;
            }
        }
        return true;
    }
    
    // is there an augmenting path?
    // if so, upon termination edgeTo[] will contain a parent-link representation of such a path
    // this implementation finds a shortest augmenting path (fewest number of edges),
    // which performs well both in theory and in practice
    bool hasAugmentingPath(FlowNetwork G, int s, int t) {
        if(edgeTo != nullptr) delete edgeTo;
        if(marked != nullptr) delete marked;
        edgeTo = new FlowEdge[G.getV()];
        marked = new bool[G.getV()];
        fill(marked, marked+G.getV(), false);
        
        // breadth-first search
        queue<int> myqueue;
        myqueue.push(s);
        marked[s] = true;
        while (!myqueue.empty() && !marked[t]) {
            int v = myqueue.front();
            myqueue.pop();
            
            for (FlowEdge e : G.getadj(v)) {
                int w = e.other(v);
                
                // if residual capacity from v to w
                if (e.residualCapacityTo(w) > 0) {
                    if (!marked[w]) {
                        edgeTo[w] = e;
                        marked[w] = true;
                        myqueue.push(w);
                    }
                }
            }
        }
        // is there an augmenting path?
        return marked[t];
    }


    
public:
    
    FordFulkerson(FlowNetwork G, int s, int t) {
        
        // while there exists an augmenting path, use it
        value = excess(G, t);
        while (hasAugmentingPath(G, s, t)) {
            // compute bottleneck capacity
            double bottle = DBL_MAX;
            for (int v = t; v != s; v = edgeTo[v].other(v)) {
                bottle = min(bottle, edgeTo[v].residualCapacityTo(v));
            }
            // augment flow
            for (int v = t; v != s; v = edgeTo[v].other(v)) {
                G.addResidualFlowTo(edgeTo[v], v, bottle);
            }
            
            value += bottle;
        }
        
        // check optimality conditions
        //assert (check(G, s, t) == true);
    }
    
    double getvalue()  {
        return value;
    }
    
    bool inCut(int v)  {
        return marked[v];
    }
    
};

int main() {
    
    // create flow network with V vertices and E edges
    int V = 6;
    int E = 10;
    int s = 0, t = V-1;
    ifstream in("input.txt");
    FlowNetwork G (in);
    
    // compute maximum flow and minimum cut
    FordFulkerson maxflow(G, s, t);
    cout << "Max flow from " << s << " to " << t << endl;
    for (int v = 0; v < G.getV(); v++) {
        for (FlowEdge e : G.getadj(v)) {
            if ((v == e.from()) && e.getFlow() > 0)
                cout << "   " << e << endl;
        }
    }
    
    
    // print min-cut
    cout << "Min cut: " << endl;
    for (int v = 0; v < G.getV(); v++) {
        if (maxflow.inCut(v)) cout << v << " ";
    }
    cout << endl;
    
    cout << "Max flow value = " << maxflow.getvalue() << endl;
}