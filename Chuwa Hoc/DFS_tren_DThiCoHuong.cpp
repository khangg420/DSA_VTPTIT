#include <bits/stdc++.h>
using namespace std;

const int ma = 1005;
vector<int> adj[ma];
bool visited[ma];

void DFS(int u, vector<int> &res) {
	visited[u] = true;
	res.push_back(u);
	for(int v : adj[u]) {
		if(!visited[v]) {
			DFS(v, res);
		}
	}
}

int main() {
	int t; cin >> t;
	while(t--) {
		int V, E, u;
		cin >> V >> E >> u;
		
		//Reset du lieu
		for(int i = 1; i <= V; i++) {
			adj[i].clear();
			visited[i] = false;
		}
		
		//Nhap danh sach canh (do thi co huong)
		for(int i = 0; i < E; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
		}
		
		//Sap xep danh sach ke de duyet dung thu tu
		for(int i = 1; i <= V; i++) {
			sort(adj[i].begin(), adj[i].end());
		}
		
		vector<int> res;
		DFS(u, res);
		for(int i = 0; i < res.size(); i++) {
			cout << res[i] << (i == res.size() - 1 ? "" : " ");
		}
		cout << endl;
	}
	return 0;
}
