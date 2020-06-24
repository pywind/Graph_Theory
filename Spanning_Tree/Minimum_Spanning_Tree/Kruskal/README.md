# Kruskal’s Minimum Spanning Tree 
> Definition: Let G be the weighted graph. The smallest spanning tree is the spanning tree whose sum of the weights of the edges is the smallest.
1. Concept
* To find the minium, we must to **SORT** up ascending.
* The constituent sets are marked as individual subsets.
* Union of subsets containing edges of increasing length. We will get a minimal spanning tree.
* Mark the vertices that have been traversed for convenience.
2. Question
* First, we must to solve three problem:
  * MAKE_SET (v): Create a set with only one vertex v.
  * FIND_SET(p): Find the set containing vertices p.
  * UNION (u, v): The assembly containing u with the set containing v forming a common set.
* Second, how do you solve the problem of storing a pair of vertices with their weights ?
  * Create a new struct or class. Or use the data type available, don't you ?
 3. Solution
 * Unification of variables
 ```
 parent: is array contain the position of vectex. parent[5] = 4. It mean element 5 is in set 4th
 - MAKE_SET:
 * I recommend using the atoi function in the <numeric> include
 ``` C++
 -> void iota (ForwardIterator first, ForwardIterator last, T val)
 iota(parent, parent + n + 1, 0);
 ```
 
