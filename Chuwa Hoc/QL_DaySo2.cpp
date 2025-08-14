#include <bits/stdc++.h>
using namespace std;

int n, a[100];
vector<string> res;

void back(int k) {
	if(k == n) {
		string tmp = "[";
		for(int i = 1; i < n; i++) {
			tmp += to_string(a[i]) + ' ';
		}
		tmp += to_string(a[n]) + ']';
		res.push_back(tmp);
	}
	else {
		for(int i = 1; i <= k; i++) {
			a[i] += a[i + 1];
		}
		// Ghi Ket qua
		string tmp = "[";
		for(int i = 1; i < k; i++) {
			tmp += to_string(a[i]) + ' ';
		}
		tmp += to_string(a[k]) + ']';
		res.push_back(tmp);
	}
	if(k > 1) back(k - 1);
}

int main() {
	int t; cin >> t;
	while(t--) {
		res.clear();
		cin >> n;
		for(int i = 1; i <=n; i++) cin >> a[i];
		back(n);
		for(int x = res.size() - 1; x >= 0; x--) {
			cout << res[x] << " ";
		}
		cout << endl;
	}
}
