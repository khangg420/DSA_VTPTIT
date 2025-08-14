#include <bits/stdc++.h>
using namespace std;

int n, a[100];
vector<string> res;

void back(int k) {
	if(k == n) {
		string tmp = "[";		//string tmp(1, '[');
		for(int i = 1; i <= n; i++) {
			tmp += to_string(a[i]) + ' ';
		}
		tmp.pop_back( );
		tmp.push_back(']');
		res.push_back(tmp);
	}
	else {
		for(int i = 1; i <= k; i++) {
			a[i] += a[i + 1];
		}
		// Ghi Ket qua
		string tmp = "[";
		for(int i = 1; i <= k; i++) {
			tmp += to_string(a[i]) + ' ';
		}
		tmp.pop_back( );
		tmp.push_back(']');
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
		for(auto x : res) cout << x << endl;
	}
}
