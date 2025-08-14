#include <bits/stdc++.h>
using namespace std;

//for (int i = 0; i < N; ++i) {
//    for (int v = V; v >= A[i]; --v) {
//        dp[v] = max(dp[v], dp[v - A[i]] + C[i]);
//    }
//}

int main() {
	int t; cin >> t;
	while(t--) {
		int n, v;
		cin >> n >> v;
		vector<int> a(n), c(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < n; i++) cin >> c[i];
		vector<int> dp(v+1,0);
		
		for(int i = 0; i < n; i++) {
			for(int j = v; j >= a[i]; j--) {
				dp[j] = max(dp[j], dp[j - a[i]] + c[i]);
			}
		}
		cout << dp[v] << endl;
	}
	return 0;
}
