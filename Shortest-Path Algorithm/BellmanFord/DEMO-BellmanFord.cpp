#include <iostream>
#include <vector>
#include <math.h>
#define MAX 99999
using namespace std;

struct Edge {
    int u, v;
};
int W[50][50];
int d[50], p[50];
void init(int& n, Edge E[], int& k) {
    cin >> n;
    k = 0;
    for (int i = 0; i < n; i++) {
        d[i] = MAX;
        for (int j = 0; j < n; j++) {
            cin >> W[i][j];
            if (W[i][j] != 0) {
                E[k].u = i;
                E[k].v = j;
                k++;
            }
        }
    }
}
void display(int i, int n) {
    cout << "i = " << i << " ";
    for (int i = 0; i < n; ++i) {
        cout << d[i] << "|" << p[i] << " ";
    }
    cout << endl;
}
bool infCompare(int x, int y) {
    return x != MAX && y != MAX;
}
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
    if (flag) cout << "Co chu trinh am !" << endl;
}
void tracing(int a, int b) {
    if (d[b] - d[a] > 0) {
        cout << "Duong di ngan nhat:" << d[b] - d[a] << endl;
        while (a != b) {
            cout << b << " ";
            b = p[b];
        }
        cout << a << endl;
    }
    else cout << "Khong co duong di !";
}
int main() {
    int n, k;
    Edge E[50];
    init(n, E, k);
    bellmanFord(E, n, k);
    tracing(1, 2);
    /*for (int j = 0; j < k; ++j) {
        cout << W[E[j].u][E[j].v] << endl;
    }*/
}