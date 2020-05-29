# **Depth-First Search**

> What's the difference between DFS vs DFS ?

> DFS process installation is more simple and compact than BFS
## Concept: 
* It's like finding your way in a matrix. Always go to the first path you see and mark it. 
* If you encounter a marked road, do not enter because it is useless. 
* So when you run out of means to mark while you're still not out of the matrix, you're stuck.
## Algorithm
> Using data structure ***stack*** 

1. **Stack**
#### Stack is data structure allows storage and access data  ***First In Last Out (LIFO)
* C++ library 
```C++ 
#include <stack> 
```
* Constructor
``` C++
 stack <data_type> name_stack
 /// declare from vector
 stack <int, vector <int>> name_stack
 ```
* Function
 
 > .empty() : *Return true if stack is empty*

 > .size() : *Return size of stack*

 > .top() : *Reference to the top (last) element*

 > .push(val) : *Copy value and insert on the last of stack*

 > .pop() : *delete the top (last) index of stack*
* C++11 :
 > .emplace() : construct and insert value

 > .swap(name_stack2) : *swap 2 stack*

 2. **Algorithm**
 #### Source code C++ with recursion:
 ```C++
vector g[maxn]; 
int D[maxn]; 
void DFS(int u) {
    D[u] = 1; // mark vertex u 
    for(int i = 0; i < g[u].size(); ++i) { // u near v
        int v = g[u][i];
        if(D[v] == 0)  { // if D[v] isn't marked
            DFS(v); 
        }
    }
}
```


#### Source code C++ without recursion by stack: 
```C++ 
 void DFS(int n) {
    D[1] = 1;
    p[1] = -1;
    stack <int> S;
    S.push(0);
    int u = 1;
    while (u != 0) {
        int v = 0;
        bool stop = false;
        while (!stop && v < n) {
            v++;
            if (W[u][v] > 0 && D[v] == 0) {
                stop = true;
            }
        }
        if (v < n) {
            if (W[u][v] > 0) {
                D[v] = 1;
                p[v] = u;
                S.push(u);
                u = v;
            }
        }
        else {
            u = S.top();
            S.pop();
        }
    }
}
``` 
#### Explain
- Push(0) to stack S
- u = 1
- while ( u != 0) 
    - Find the first point (in order) near by u that has not yet passed by using while:
        - Set a bool stop and v
        - while !stop , v = 0 -> n
        - if we meet a vertex has passed yet -> stop
    - If it have a point has marked, Mark D[v] = 1, pre[v] = u
        - push(u) to S
        - u = v
    - Else there is no point (all points have passed) 
        - u = top of S
        - delete top S
    
- End while

3. **Complexity**
* Space: 2|V| and |V| is number of vertices.
* Time: O( |V| + |E| ), with V and E are set of vertices and edges, DFS always calls a point one time only.
4. **Tracing**
    #### If you have had declared array pre, you can call pre[v] as a node leading to v in DFS process 
> The path from pre[v] = u is the shortest way from u to v

* Note: if you find the way from u to v in D FS process, you must start from u
> The recursion is: pre[ pre[ pre...[v]]] = u
5. **Application**
* Identify the connected components of a graph.
* Topological arrangements for graphs.
* Identify the strongly connected components of a directed graph.
* Check if a graph is a flat graph.
