/*************************************************************************
	> File Name: Floyd_Warshall.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Tue Nov  3 17:10:56 2015
 ************************************************************************/
#include<cstdio>
#include<vector>
#define V 5
#define INF 99999

using namespace std;

int dist[V][V];
int Pre[V][V];

void printSolution();
void printPre();

void floydWarshell (int graph[][V])
{
    int i, j, k;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
            if(i == j || graph[i][j] == INF) Pre[i][j] = INF;
            else Pre[i][j] = i+1;
        }
    }
    
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    Pre[i][j] = Pre[k][j];
                }
            }
        }
    }
    
    printSolution();
    printPre();
}

void printSolution()
{
    printf ("Following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void printPre()
{
    printf ("Following matrix shows the Pre \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (Pre[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", Pre[i][j]);
        }
        printf("\n");
    }
}

void findPath(int start, int end) {
    vector<int> paths;
    paths.push_back(end);
    while(Pre[start-1][end-1] != start) {
        paths.push_back(Pre[start-1][end-1]);
        end = Pre[start-1][end-1];
    }
    paths.push_back(start);
    printf("The path : ");
    for(int i = paths.size()-1;i >= 0;i--)
        printf("%i ", paths[i]);
    printf("\n");
}

int main()
{
    int graph[V][V] = {
        {0,   3,  8, INF, -4},
        {INF, 0, INF,  1, 7},
        {INF, 4, 0,   INF,INF},
        {2, INF, -5, 0, INF},
        {INF, INF, INF, 6, 0}
    };
    
    floydWarshell(graph);
    findPath(2, 5);
    return 0;
}