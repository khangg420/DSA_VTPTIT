#include <bits/stdc++.h>
using namespace std;

const int ma = 1005;
vector<int> adj[ma];
bool visited[ma];
int parent[ma];

void DFS(int u) {
	visited[u] = true;
	for(int v : adj[u]) {
		if(!visited[v]) {
			parent[v] = u;
			DFS(v);
		}
	}
}

void findPath(int s, int t) {
	if(!visited[t]) {
		cout << -1 << endl;
		return;
	}
	vector<int> path;
	for(int v = t; v != s; v = parent[v]) {
		path.push_back(v);
	}
	path.push_back(s);
	reverse(path.begin(), path.end());
	for(int v : path) 
		cout << v << " ";
	cout << endl;
}

int main() {
	int t; cin >> t;
	while(t--) {
		int V, E, s, t;
		cin >> V >> E >> s >> t;

		memset(visited, false, sizeof(visited));
		memset(parent, -1, sizeof(parent));
		
		//Reset du lieu
//		for(int i = 1; i <= V; i++) {
//			adj[i].clear();
//			visited[i] = false;
//			parent[i] = -1;
//		}
		
		//Nhap danh sach canh (do thi vo huong)
		for(int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u); //Them chieu nguoc lai
		}
		DFS(s);
		findPath(s, t);
	}
	return 0;
}
