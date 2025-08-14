#include <bits/stdc++.h>
using namespace std;


int main() {
	int t; cin >> t;
	while(t--) {
		int n, m; cin >> n >> m;
		vector<int> adj[n + 1];
		for(int i = 0; i < m; i++){
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		for(int i = 1; i <= n; i++) {
			cout << i << ": ";
			for(int x : adj[i]) {
				cout << x << " ";
			}
			cout << endl;
		}
	}
}
