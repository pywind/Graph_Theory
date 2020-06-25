
# Kruskal’s Minimum Spanning Tree

> Definition: Let G be the weighted graph. The smallest spanning tree is the spanning tree whose sum of the weights of the edges is the smallest.

1. Concept

* To find the minium, we must to **SORT** up ascending.
* The constituent sets are marked as individual subsets.
* Union of subsets containing edges of increasing length. We will get a minimal spanning tree.
* Mark the vertices that have been traversed for convenience.

2.Question

* First, we must to solve three problem:
  * MAKE_SET (v): Create a set with only one vertex v.
  * FIND_SET(p): Find the set containing vertices p.
  * UNION (u, v): The assembly containing u with the set containing v forming a common set.
* Second, how do you solve the problem of storing a pair of vertices with their weights ?
  * Create a new struct or class. Or use the data type available, don't you ?

3.Solution

#### Unification of variables

> parent: is array contain the position of vertex. parent[5] = 4. It mean element 5 is in set 4th

### `MAKE_SET`

I recommend using the atoi function in the numeric include
-> void iota (ForwardIterator first, ForwardIterator last, T val)

     iota(parent, parent + n + 1, 0)

> Or if you want the simple way, you can use a for statement

### `FIND_SET`
* Aim: we must find Which is set contain index i in parent array.
* In MAKE_SET, we assign index i in set ith. It mean in program, parent[i] = i!
* So, if parent[p] == p, we return p.
  * Else, return parent[p] = find_Set(parent[p])
  
> Why ?

* I have a example, we have a parent array like below:

```
0 1 2 5 6 5 6
```
* EX:FIND_SET(4): parent[4] = 6 != 4
  * Then, parent[4] = FIND_SET(6)
  * return parent[6] = 6
  * OK, return parent[4] = 6
  * It mean, index 4 is in 6th set in gather with index 6. {4, 6}
```C++
int findSet(int p) {
	 if (parent[p] == p)
		  return p;
	 else
		  parent[p] = findSet(parent[p]);
	 return parent[p];
}
```
### `UNION`
* Aim: Define u with the set containing v forming a common set.
* parent[FIND_SET(u)] = FIND_SET(v)
* Have you wondering why use assignment not another !
* Turn it back, the elements have been linked together. For example: {3, 5, 6} are almost equal to 6. so if you need to change 6 with another number then when retrieving next time, the values 3, 5 will automatically change.

