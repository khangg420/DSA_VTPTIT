#include <bits/stdc++.h>
using namespace std;

int n, m, u;
vector<int> adj[1001];
bool visited[1001];

void input(int n, int m) {
	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
//		adj[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
}

void dfs(int u) {
	cout << u << " ";
	// Danh dau dinh u da duoc tham
	visited[u] = true;
	for(int v : adj[u]) {
		if(visited[v] == false) {
			dfs(v);
		}
	}
}

int main() {
	int t; cin >> t;
	while(t--) {
		cin >> n >> m >> u;
		input(n, m);
		dfs(u);
	}

}
