#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> adj[1001];
bool visited[1001];

void input() {
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
}

// KTRA chu trinh
bool DFS(int u, int parent) {
	visited[u] = true;
	for(int v : adj[u]) {
		if(!visited[v]) {
			if(DFS(v, u))
				return true;
		}
		else if(v != parent) {
			return true;
		}
	}
	return false;
}

// KTRA tinh lien thong
bool lienthong() {
	for(int i = 1; i <= n; i++) {
		if(!visited[i]) return false;
	}
	return true;
}

int main() {
	int t; cin >> t;
	while(t--) {
		for(int i = 1; i <= 1000; i++) adj[i].clear();
		input();
		bool cochutrinh = DFS(1, 0);
		if(cochutrinh || !lienthong()) {
			cout << "NO" << endl;
		}
		else cout << "YES" << endl;
	}
}
