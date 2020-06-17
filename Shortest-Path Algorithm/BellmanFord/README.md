# Bellman–Ford Algorithm
> Given a graph and a source vertex src in graph, find shortest paths from src to all vertices in the given graph. The graph may contain negative weight edges.
```C++
void bellmanFord(Edge E[], int n, int k) {
    d[0] = 0;
    p[0] = -1;
    display(0, n);
    bool flag = false;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < k; j++) {
            int u = E[j].u;
            int v = E[j].v;
            if (d[u] + W[u][v] < d[v] && infCompare(d[u],d[v]) ) {
                d[v] = d[u] + W[u][v];
                p[v] = u;
                flag = true;
            }
        }
        display(i, n);
    }
    if (flag) cout << "Graph contains negative weight cycle" << endl;
}
```