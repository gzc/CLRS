### Problems 3 : Euler tour
***
An Euler tour of a connected, directed graph G = (V, E) is a cycle that traverses each edge of G exactly once, although it may visit a vertex more than once.
### `Answer`
**a.**

只有入度=出度,才能进来一次又出去;否则,不对称,是不可能访问全部的边的.

**b.**

[implementation](./exercise_code/EulerTour.cpp)

### Problems 4 : Reachability
Let G = (V, E) be a directed graph in which each vertex u in V is labeled with a unique integer L(u) from the set {1, 2,..., |V|}. For each vertex u in V, let ￼ be the set of vertices that are reachable from u. Define min(u) to be the vertex in R(u) whose label is minimum, i.e., min(u) is the vertex v such that L(v) = min {L(w) : w in R(u)}. Give an O(V + E)-time algorithm that computes min(u) for all vertices u in V.

### `Answer`



***
Follow [@louis1992](https://github.com/gzc) on github to help finish this task.
