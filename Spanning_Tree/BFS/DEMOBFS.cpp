#include <iostream>
#include <queue>


using namespace std;

int D[50];
int p[50];

//void init(int W[][50], int& c) {
//    cin >> c;
//    for (int i = 0; i < c; ++i) {
//        D[i] = 0;
//        for (int j = 0; j < c; ++j) {
//            cin >> W[i][j];
//        }
//    }
//}
void init(int W[][50], int& n, int& m, int& s) {
    cin >> n >> m >> s;
    // <++ n vertex m edge ++>
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        W[u][v] = 1;
        W[v][v] = 1;
        D[i] = 0;
    }
}

void BFS(int W[][50], int n, int m, int s) {
    D[s] = 1;
    p[s] = -1;
    queue <int> Q;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front();
        for (int v = 1; v <= n; ++v) {
            if ((W[u][v] > 0) && !D[v]) {
                D[v] = 1;
                p[v] = u;
                Q.push(v);
            }
        }
        Q.pop(); 
    }
}
void tracing(int n) {
    for (int i = 1; i <= n; ++i) {
        if (p[i] > 0)
            cout << i << " -> " << p[i] << endl;
        else 
            cout << i << ": " << "Root" << endl;
    }
}
int main() {
    int n, m, s;
    int W[50][50];
    init(W, n, m, s);
    BFS(W, n, m, s);
    cout << "Spanning tree " << endl;
    tracing(n);
}


/*
9
0 0 0 0 0 0 0 0 0
0 0 2 0 4 0 0 7 0
0 1 0 3 0 0 0 7 0
0 0 2 0 4 0 6 0 0
0 1 0 3 0 5 0 0 0
0 0 0 0 4 0 6 7 0
0 0 0 3 0 5 0 0 8
0 1 2 0 0 5 0 0 0
0 0 0 0 0 0 6 0 0
*/
/*test 2
7 7 1
1 2
1 3
1 5
2 4
2 6
3 7
5 6

*/
