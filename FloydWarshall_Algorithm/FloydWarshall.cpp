#include <iostream>
#define INF 99999

using namespace std;

int W[50][50], d[50][50], p[50][50];
void init(int& n) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> W[i][j];
            if (W[i][j] == 0) W[i][j] = INF;
            d[i][j] = W[i][j];
            if (i != j) {
                p[i][j] = i;
            }
            else p[i][j] = -1;
        }
    }
}

void FloydWarshall(int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = p[k][j];
                }
            }
        }
    }
}
void printPath(int i, int j) {
    if (i == j) cout << i << " ";
    else {
        printPath(i, p[i][j]);
        cout << j << " ";
    }
}
void tracing(int a, int b) {
    if (p[a][b] == -1) {
        cout << "Khong co duong di !";
    }
    else {
        cout << "Duong di ngan nhat: " << d[a][b] << endl;
        printPath(a, b);
    }
}
int main() {
    int n;
    init(n);
    FloydWarshall(n);
    tracing(1, 2);
}


