#include <bits/stdc++.h>
using namespace std;


string Sinh(string s) {
	for(int i = 1; i < s.length(); i++) {
		if (s[i] > s[i - 1]) {
			next_permutation(s.begin(), s.end());
			return s;
		}
	}
	return "BIGGEST";
}

int main() {
	int t; cin >> t;
	while(t--) {
		int a; cin >> a;
		string s; cin >> s;
		cout << a << " ";
		cout << Sinh(s) << endl;
	}
}
