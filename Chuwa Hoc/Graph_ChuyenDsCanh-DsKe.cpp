#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];

int main() {
	int t; cin >> t;
	while(t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
		for(int i = 0; i < m; i++) {
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		for(int i = 1; i <= n; i++) {
			cout << i << ":";
			for(int v : adj[i]) {
				cout << " " << v;
			}
			cout << endl;
		}
	}
}
