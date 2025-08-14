#include <bits/stdc++.h>
using namespace std;


int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<int> dp(n, 0);
		dp[0] = a[0], dp[1] = a[1];
		dp[2] = a[0] + a[2];
		for(int i = 3; i < n; i++) {
			dp[i] = a[i] + max(dp[i-2], dp[i-3]);
		}
		cout << max(dp[n-2], dp[n-1]) << endl;
	}
}
