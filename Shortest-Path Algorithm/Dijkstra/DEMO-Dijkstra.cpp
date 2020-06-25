#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 9999

using namespace std;
int W[50][50] = { 0 };
int d[50], p[50];
vector<int> T;

void init(int& n) {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		T.push_back(i);
		d[i] = MAX;
		for (int j = 0; j < n; ++j) {
			cin >> W[i][j];
		}
	}
}
void findAndDelete(int x) {
	vector<int>::iterator found;
	found = find(T.begin(), T.end(), x);
	//if (found != T.end() && T.size() > 0)
	T.erase(found);
}
void display(int i, int u, int n) {
	cout << "i = " << i << " " << "u = " << u << " ";
	for (int i = 0; i < n; ++i) {
		cout << d[i] << "|" << p[i] << " ";
	}
	cout << endl;
}
int minElement() {
	int min = MAX;
	int pos = 0;
	for (int i = 0; i < T.size(); ++i) {
		if (d[T[i]] < min) {
			min = d[T[i]];
			pos = T[i];
		}
	}
	return pos;
}
void Dijkstra(int n) {
	d[0] = 0;
	p[0] = -1;
	int i = 1;
	while (T.size() > 0) {
		int u = minElement();
		findAndDelete(u);
		for (int k = 0; k < T.size(); ++k) {
			int v = T[k];
			if (W[u][v] > 0) {
				if (d[v] > d[u] + W[u][v]) {
					d[v] = d[u] + W[u][v];
					p[v] = u;
				}
			}
		}
		//display(i, u, n);
		i++;
	}
}
void tracing(int a, int b) {
	if (a != b) {
		tracing(a, p[b]);
	}
	cout << " -> " << b;
}
int main() {
	int n, a, b;
	init(n);
	Dijkstra(n);
	cout << "Tuyen duong a -> b: ";
	cin >> a >> b;
	cout << "Duong di ngan nhat tu a -> b: " << d[b] - d[a] << endl;
	cout << "Tuyen duong: ";
	tracing(a, b);
	//1. d[b] - d[a] la duong di ngan nhat tu dinh b -> a
	//trong duong di ngan nhat
	//2. truy vet: mang p danh dau duong di p[j] = i 
	//    neu i la dinh truoc j 
}
/*
3
0 3 5 
0 0 1
0 0 0 
Tuyen duong a -> b: 0 2
Duong di ngan nhat tu a -> b: 4
Tuyen duong:  -> 0 -> 1 -> 2
*/
