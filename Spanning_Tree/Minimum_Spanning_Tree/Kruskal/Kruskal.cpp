#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

#define weight first
#define arris second
using namespace std;

// <--->
typedef pair<int, int> VE;
typedef pair<int, VE> node;
// weight, <v, e> weight is first . 1st: v, 2nd: e 
vector<node> edge;
vector<VE> A;
//
int n, m;
int parent[2001];
//

void init() {
    cin >> n >> m;
    while (m--) {
        int e, v, w;
        cin >> v >> e >> w;
        edge.push_back(node(w, VE(v, e)));
    }
    

}
void display() {
    for (int i = 0; i <= n; ++i) {
        cout << parent[i] << " ";
    }
    cout << endl;
}
int findSet(int p) { 
    if (parent[p] == p)
        return p;
    else
        return parent[p] = findSet(parent[p]);
}
void join(int u, int v) { 
    parent[findSet(u)] = findSet(v); 
}
void makeSet() {
    iota(parent, parent + n + 1, 0);
}



int main() {
    // Reading data 
    init();
    // Create a set with only one vertex contain v
    makeSet();
    // Sort by first: weight
    sort(edge.begin(), edge.end());

    //vector<node>::iterator index;
    int mst_weight = 0;
    display();
    for (auto index = edge.begin(); index != edge.end(); index++) {
        int u = index->arris.weight;
        int v = index->arris.arris;
        if (findSet(u) != findSet(v)) {
            join(u, v);
            mst_weight += index->weight;
            A.push_back(index->arris);
            display();
        }
    }
    cout << mst_weight << endl;
    /*sort(A.begin(), A.end());
    for (auto i : A) {
        cout << i.weight << " " << i.arris << endl;
    }*/
}
/*

6  9
1  2  33
1  3  17
2  4  20
2  3  18
3  4  16
3  5  4
4  5  9
4  6  8
5  6  14

*/
