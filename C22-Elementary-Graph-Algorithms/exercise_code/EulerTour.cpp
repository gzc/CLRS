/*************************************************************************
	> File Name: EulerTour.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Thu Jul 16 13:54:43 2015
 ************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

#define MAX_VERTEX 10005

typedef struct {
    int end_vertex;
    int visited;
} Edge;

int Nvertex;
int Nedge;
vector<Edge> vertex[MAX_VERTEX];

static void input() {
    int i, u, v;
    Edge tmp;
    tmp.visited = 0;
    cin >> Nvertex >> Nedge;
    for (i = 0; i < Nedge; ++i) {
        cin >> u >> v;
        tmp.end_vertex = u;
        vertex[v].push_back(tmp);
        tmp.end_vertex = v;
        vertex[u].push_back(tmp);
    }
}

static void euler(int x) {
    int i;
    for (i = vertex[x].size() - 1; i >= 0; --i) {
        if (!vertex[x][i].visited) {
            vertex[x][i].visited = 1;
            euler(vertex[x][i].end_vertex);
        }
    }
    cout << x << endl;
}

int main() {
    input();
    euler(1);
    return 0;
}


