# Minimum Spanning Trees
## Spanning trees
A spanning tree of a graph is just a subgraph that contains all the vertices and is a tree. A graph may have many spanning trees; for instance the complete graph on four vertices
```
    o---o
    |\ /|
    | X |
    |/ \|
    o---o
```
has sixteen spanning trees:
    o---o    o---o    o   o    o---o
    |   |    |        |   |        |
    |   |    |        |   |        |
    |   |    |        |   |        |
    o   o    o---o    o---o    o---o

    o---o    o   o    o   o    o   o
     \ /     |\ /      \ /      \ /|
      X      | X        X        X |
     / \     |/ \      / \      / \|
    o   o    o   o    o---o    o   o

    o   o    o---o    o   o    o---o
    |\  |       /     |  /|     \
    | \ |      /      | / |      \
    |  \|     /       |/  |       \
    o   o    o---o    o   o    o---o

    o---o    o   o    o   o    o---o
    |\       |  /      \  |       /|
    | \      | /        \ |      / |
    |  \     |/          \|     /  |
    o   o    o---o    o---o    o   o
## Minimum spanning trees
Now suppose the edges of the graph have weights or lengths. The weight of a tree is just the sum of weights of its edges. Obviously, different trees have different lengths. The problem: how to find the minimum length spanning tree?
This problem can be solved by many different algorithms. It is the topic of some very recent research. There are several "best" algorithms, depending on the assumptions you make:

A randomized algorithm can solve it in linear expected time. 
It can be solved in linear worst case time if the weights are small integers.
Otherwise, the best solution is very close to linear but not exactly linear. The exact bound is O(m log beta(m,n)) where the beta function has a complicated definition: the smallest i such that log(log(log(...log(n)...))) is less than m/n, where the logs are nested i times.
These algorithms are all quite complicated, and probably not that great in practice unless you're looking at really huge graphs. The book tries to keep things simpler, so it only describes one algorithm but (in my opinion) doesn't do a very good job of it. I'll go through three simple classical algorithms (spending not so much time on each one).
## Why minimum spanning trees?
The standard application is to a problem like phone network design. You have a business with several offices; you want to lease phone lines to connect them up with each other; and the phone company charges different amounts of money to connect different pairs of cities. You want a set of lines that connects all your offices with a minimum total cost. It should be a spanning tree, since if a network isn't a tree you can always remove some edges and save money.
A less obvious application is that the minimum spanning tree can be used to approximately solve the traveling salesman problem. A convenient formal way of defining this problem is to find the shortest path that visits each point at least once.

Note that if you have a path visiting all points exactly once, it's a special kind of tree. For instance in the example above, twelve of sixteen spanning trees are actually paths. If you have a path visiting some vertices more than once, you can always drop some edges to get a tree. So in general the MST weight is less than the TSP weight, because it's a minimization over a strictly larger set.

On the other hand, if you draw a path tracing around the minimum spanning tree, you trace each edge twice and visit all points, so the TSP weight is less than twice the MST weight. Therefore this tour is within a factor of two of optimal. There is a more complicated way (Christofides' heuristic) of using minimum spanning trees to find a tour within a factor of 1.5 of optimal; I won't describe this here but it might be covered in ICS 163 (graph algorithms) next year.

## How to find minimum spanning tree?
The stupid method is to list all spanning trees, and find minimum of list. We already know how to find minima... But there are far too many trees for this to be efficient. It's also not really an algorithm, because you'd still need to know how to list all the trees.
A better idea is to find some key property of the MST that lets us be sure that some edge is part of it, and use this property to build up the MST one edge at a time.

For simplicity, we assume that there is a unique minimum spanning tree. (Problem 4.3 of Baase is related to this assumption). You can get ideas like this to work without this assumption but it becomes harder to state your theorems or write your algorithms precisely.

Lemma: Let X be any subset of the vertices of G, and let edge e be the smallest edge connecting X to G-X. Then e is part of the minimum spanning tree.
Proof: Suppose you have a tree T not containing e; then I want to show that T is not the MST. Let e=(u,v), with u in X and v not in X. Then because T is a spanning tree it contains a unique path from u to v, which together with e forms a cycle in G. This path has to include another edge f connecting X to G-X. T+e-f is another spanning tree (it has the same number of edges, and remains connected since you can replace any path containing f by one going the other way around the cycle). It has smaller weight than t since e has smaller weight than f. So T was not minimum, which is what we wanted to prove.
