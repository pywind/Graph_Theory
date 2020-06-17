# C++ Program for shortest path algorithm 
## Given a graph and a source vertex in the graph, find shortest paths from source to all vertices in the given graph.
```C++
void Dijkstra(int n) {
    d[0] = 0;
    p[0] = -1;
    while (T.size() > 0) {
        int u = minElement();
        findAndDelete(u);
        for (int k = 0; k < T.size(); ++k) {
            int v = T[k];
            if (W[u][v] > 0) {
                if (d[v] > d[u] + W[u][v]) {
                    d[v] = d[u] + W[u][v];
                    p[v] = u;
                }
            }
        }     
    }
}
```
