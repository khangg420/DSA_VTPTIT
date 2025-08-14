#include <bits/stdc++.h>
using namespace std;

int n, m;
set <int> adj[1001];
int deg[1001];

void nhap() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].insert(y);
		adj[y].insert(x);
		deg[x]++;
		deg[y]++;
	}
}

int main() {
	int t; cin >> t;
	while(t--) {
		nhap();
		int odd = 0;
		for(int i = 1; i <= n; i++) {
			if(deg[i] % 2 == 1) {
				odd++;
			}
		}
		if(odd == 0) cout << 2 << endl;
		else if(odd == 2) cout << 1 << endl;
		else cout << 0 << endl;
	}
	return 0;
}
