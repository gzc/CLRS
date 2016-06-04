### Problems 3 : Euler tour
***
An Euler tour of a connected, directed graph G = (V, E) is a cycle that traverses each edge of G exactly once, although it may visit a vertex more than once.

a. Show that G has an Euler tour if and only if in-degree (v) = out-degree (v) for each vertex v in V.

b. Describe an O(E)-time algorithm to find an Euler tour of G if one exists. (Hint: Merge edge-disjoint cycles.)


### `Answer`
**a.**

只有入度=出度,才能进来一次又出去;否则,不对称,是不可能访问全部的边的.

**b.**

[implementation](./exercise_code/EulerTour.cpp)

### Problems 4 : Reachability
Let G = (V, E) be a directed graph in which each vertex u in V is labeled with a unique integer L(u) from the set {1, 2,..., |V|}. For each vertex u in V, let ￼ be the set of vertices that are reachable from u. Define min(u) to be the vertex in R(u) whose label is minimum, i.e., min(u) is the vertex v such that L(v) = min {L(w) : w in R(u)}. Give an O(V + E)-time algorithm that computes min(u) for all vertices u in V.

### `Answer`

    For every vertex v in G
      Mark v undiscovered
    For every undiscovered vertex v in G, starting with the lowest L-value
      R(v) = L(v)
      Mark v discovered.
      Perform Reverse-DFS from v.
        For every undiscovered vertex u we encounter on this DFS:
          R(u) = R(v)
          Mark u discovered. 


[reference](http://www.fongboy.com/classes/cs180/hw7-sol.pdf)


***
Follow [@louis1992](https://github.com/gzc) on github to help finish this task.

