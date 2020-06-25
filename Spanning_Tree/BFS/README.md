# **Breadth-First Search**
## Concept: 
* By using the BFS process, we will browse the spreading graph in layers from the vertex u and we will find the shortest path to another vertex. And BFS is a good way to find out which vertex can't be reached from u.
## Algorithm
> Using data structure ***queue*** 
### Queue is data structure allows storage and access data ***First In First Out (FIFO)***
1. **Queue**
* C++ library 
``` C++ 
#include <queue> 
```
* Constructor
``` C++
 queue <data_type> name_queue
 /// declare from list
 queue <int, list <int>> name_queue
 ```
* Functions
 
 > .empty() : *Return true if queue is empty*

 > .size() : *Return size of queue*

 > .front() : *Reference to the first element*

 > .back() : *Reference to the last element*

 > .push(val) : *Copy value and insert on the last of queue*

 > .pop() : *delete the first index of queue*
* C++11 :
 > .emplace() : construct and insert value

 > .swap(name_queue2) : *swap 2 queue*

2. `Algorithm analyst`
 #### Source code C++ :
 ``` C++ 
 void BFS(int W[][50], int n, int m, int s) {
    D[1] = 1;
    pre[1] = -1;
    queue <int> Q;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v = 1; v <= n; ++v) {
            if (W[u][v] > 0 && D[v] == 0) {
                D[v] = 1;
                pre[v] = u;
                Q.push(v);
            }
        }
    }
}
``` 
### Explain
- Queue Q is clear
- while (Q != empty) 
    - u = the top of queue and delete top queue
    - Spread out to all vertices adjacent to u that have not yet been passed :
        - mark vertex v 
        - assign the path before v = u
        - push v into Q 
    
- End while

3. **Complexity**
* Space: 2|V| and |V| is number of vertices
* Time: O( |V| + |E| ), with V and E are set of vertices and edges, because in the worst case, any vertices and edges will be visit once.  
4. **Tracing**
#### If you have had declared array pre, you can call pre[v] as a node leading to v in BFS process 
> The path from pre[v] = u is the shortest way from u to v

* Note: if you find the way from u to v in BFS process, you must start from u
> The recursion is: pre[ pre[ pre...[v]]] = u
5. **Application**
* Search the path from a root to another or back, or search the path from a root to all other vertices.
* This algorithm is also used to find connected components of the graph, or check the two-sided graph.


