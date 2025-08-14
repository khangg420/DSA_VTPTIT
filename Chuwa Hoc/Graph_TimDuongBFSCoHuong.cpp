#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

void bfs(int u) {
	queue <int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()) {
		int v = q.front(); q.pop();
		
		if(v == t) return;
		for(int x : adj[v]) {
			if(!visited[x]) {
				visited[x] = true;
				q.push(x);
				parent[x] = v;
			}
		}
	}
}

void Path(int s, int t) {
	bfs(s);
	if(!visited[t]) {
		cout << -1 << endl;
	}
	else {
		vector<int> path;
		while(t != s) {
			path.push_back(t);
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
//			adj[y].push_back(x);
		}
		
		Path(s, t);
	}
	return 0;
}
