# Dijkstra’s shortest path algorithm
> Given a graph and a source vertex in the graph, find shortest paths from source to all vertices in the given graph.
> Dijkstra’s algorithm is very similar to Prim’s algorithm for minimum spanning tree. Like Prim’s MST, we generate a SPT (shortest path tree) with given source as root. We maintain two sets, one set contains vertices included in shortest path tree, other set includes vertices not yet included in shortest path tree. At every step of the algorithm, we find a vertex which is in the other set (set of not yet included) and has a minimum distance from the source.
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