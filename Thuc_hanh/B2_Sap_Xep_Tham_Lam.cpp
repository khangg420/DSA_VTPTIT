#include <bits/stdc++.h>
using namespace std;


void solve(){
	int n; cin >> n;
	int a[n], b[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	int l = 0, r = n - 1;
	while(l <= r) {
		int ma = max(a[l], a[r]);
		int mi = min(a[l], a[r]);
		if(mi != b[l] || ma != b[r]) {
			cout << "No\n";
			return;
		}
		l++;
		r--;
	}
	cout << "Yes\n";	
}

int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}
}
