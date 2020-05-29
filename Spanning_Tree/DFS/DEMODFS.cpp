#include <iostream>
#include <stack>

using namespace std;

int W[50][50];
int D[50] = { 1 }, p[50] = { 0 };
//void init(int& n) {
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; ++j) {
//            cin >> W[i][j];
//        }
//    }
//}
void init(int n, int m, int s) {
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            int u, v;
            cin >> u >> v;
            W[u][v] = 1;
        }
    }
}
void display(stack <int> s, int n, int u, int v) {
    cout << u << " " << v << " |";
    while (!s.empty()) {
        cout << s.top() << ",";
        s.pop();
    }
    cout << " | ";
    for (int i = 1; i < n; ++i) {
        cout << D[i] << "," << p[i] << " ";
    }
    cout << endl;
}
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
        display(S, n, u, v);
    }
}
void tracing(int n) {
    if (n != -1) {
        tracing(p[n]);
        cout << n << " ";
    }
}
int main() { 
    int n, m ,s;
    init(n, m, s);
    DFS(n);
    cout << "Cay khung by DFS: ";
    tracing(n - 1);
}
//9
//0 0 0 0 0 0 0 0 0
//0 0 2 0 4 0 0 7 0
//0 1 0 3 0 0 0 7 0
//0 0 2 0 4 0 6 0 0
//0 1 0 3 0 5 0 0 0
//0 0 0 0 4 0 6 7 0
//0 0 0 3 0 5 0 0 8
//0 1 2 0 0 5 0 0 0
//0 0 0 0 0 0 6 0 0
//test 2
//7 7 1
//1 2
//1 3
//1 5
//2 4
//2 6
//3 7
//5 6