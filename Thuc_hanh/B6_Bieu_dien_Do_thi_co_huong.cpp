#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a[n+1];
    while(m--){
        int u, v; cin >> u >> v;
        a[u].push_back(v);
    }
	for(int i = 1; i <= n; ++i) {
		sort(a[i].begin(), a[i].end());
	}
    for(int i = 1; i <= n; ++i){
        cout << i << ": ";
        for(auto x : a[i]){
            cout << x << " ";
        }
        cout << "\n";
    }
}

int main() {
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
	    vector<int> a[n+1];
	    while(m--){
	        int u, v; cin >> u >> v;
	        a[u].push_back(v);
	    }
		for(int i = 1; i <= n; ++i) {
			sort(a[i].begin(), a[i].end());
		}
	    for(int i = 1; i <= n; ++i){
	        cout << i << ": ";
	        for(auto x : a[i]){
	            cout << x << " ";
	        }
	        cout << "\n";
    	}
    }
}
