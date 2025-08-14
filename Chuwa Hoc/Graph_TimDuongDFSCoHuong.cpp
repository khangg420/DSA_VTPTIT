#include <bits/stdc++.h>
using namespace std;

//*********** Khac vo huong o cho nhap danh sach canh adj chi có 1 dòng : adj[x].push_back(y);
/* 
		for(int i = 0; i < m; i++) {
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
		}
*/

int n, m, s, t;
vector<int> adj[1001];	// Mang cac vector de luu danh sach ke
bool visited[1001];		// Mang visited check dinh da tham 
int parent[1001];		// Mang Ktra cha cua 1 dinh

void dfs(int u) {
	visited[u] = true;
	for(int v : adj[u]) {
		if(!visited[v]) {
			// Ghi nhan cha cua v la u
			parent[v] = u;
			dfs(v);
		}
	}
}

void Path(int s, int t) {
	dfs(s);
	if(!visited[t]) {
		cout << -1 << endl;
		return;
	}
	else {
		// Truy vet duong di
		vector<int> path;
		//Bat dau tu dinh t
		while(t != s) {
			path.push_back(t);
			// Lan nguoc lai
			t = parent[t];
		}
		path.push_back(s);
		reverse(path.begin(), path.end());
		for(int x : path) {
			cout << x << " ";
		}
		cout << endl;
	}
}

int main() {
	int T; cin >> T;
	while(T--) {
		cin >> n >> m >> s >> t;
		memset(visited, false, sizeof(visited));
		memset(parent, -1, sizeof(parent));
		
		for(int i = 0; i < m; i++) {
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
		}
		Path(s, t);
	}
	return 0;
}
