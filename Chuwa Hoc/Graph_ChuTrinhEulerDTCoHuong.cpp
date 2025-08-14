#include <bits/stdc++.h>
using namespace std;

int n, m;
set <int> adj[1001];
int indeg[1001];
int outdeg[1001];

void nhap() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].insert(y);
		outdeg[x]++;
		indeg[y]++;
	}
}

int main() {
	int t; cin >> t;
	while(t--) {
		nhap();
		int ok = 1;
		for(int i = 1; i <= n; i++) {
			if(indeg[i] != outdeg[i]) {
				ok = 0;
				break;
			}
		}
		if(ok) cout << 1 << endl;
		else cout << 0 << endl;
	}
	return 0;
}
