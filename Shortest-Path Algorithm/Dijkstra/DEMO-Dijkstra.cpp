#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 9999

using namespace std;

int W[50][50] = { 0 };
int d[50], p[50];
vector<int> T;

void init(int& n) {
	int e;
	cin >> n >> e;
	for (int i = 0; i < n; ++i) {
		T.push_back(i);
		d[i] = MAX;
	}
	for (int i = 0; i < e; ++i) {
		int x, y, w;
		cin >> x >> y >> w;
		W[x][y] = w;
	}
}

void display(int i, int u, int n) {
	cout << "u = " << u << " ";
	for (int i = 0; i < n; ++i) {
		cout << d[i] << "|" << p[i] << " ";
	}
	cout << endl;
}
int minElement() {
	int _min = MAX;
	int pos = 0;
	for (int i = 0; i < T.size(); ++i) {
		if (d[T[i]] < _min) {
			_min = d[T[i]];
			pos = i;
		}
	}
	return pos;
}
void deleteElement(int pos) {
	T.erase(T.begin() + pos);
}
void Dijkstra(int n) {
	d[0] = 0;
	p[0] = -1;
	int i = 1;
	while (T.size() > 0) {
		int x = minElement();
		// Chon u voi d[u] be nhat
		int u = T[x];
		// T = T - {u}
		// x la index cua phan tu u, thong qua x de xu ly u
		deleteElement(x);
		// Voi moi v thuoc T, ke voi u
		// Tuc co ton tai duong di tu u den v <=> W[u][v] co trong so
		for (int k = 0; k < T.size(); ++k) {
			int v = T[k];
			if (W[u][v] > 0) {
				if (d[v] > d[u] + W[u][v]) {
					d[v] = d[u] + W[u][v];
					p[v] = u;
				}
			}
		}
		display(i, u, n);
		i++;
	}
}
void tracing(int a, int b) {
	while (a != b && b >= 0) {
		cout << b << " --> ";
		b = p[b];
	}
	cout << a << endl;
}
int main() {
	int n, a, b;
	init(n);
	Dijkstra(n);
	cout << "Tuyen duong a -> b: ";
	cin >> a >> b;
	cout << "Duong di ngan nhat tu " << a << " -> " << b << ": " << d[b] - d[a] << endl;
	cout << "Tuyen duong: ";
	tracing(a, b);
	//1. d[b] - d[a] la duong di ngan nhat tu dinh b -> a
	//trong duong di ngan nhat
	//2. truy vet: mang p danh dau duong di p[j] = i 
	//    neu i la dinh truoc j 
}
/*
5 10
0 1 10
0 2 5
1 2 2
1 3 1
2 1 3
2 3 9
2 4 2
3 4 4
4 3 6
4 0 7
Tuyen duong a -> b: 0 4
Duong di ngan nhat tu 0 -> 4: 7
Tuyen duong:  4 --> 2 --> 0
*/
