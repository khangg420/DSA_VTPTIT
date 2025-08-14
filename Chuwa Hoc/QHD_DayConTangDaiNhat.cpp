#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int t; cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		// L[i] : Do dai cua day con tang dai nhat ket thuc o chi so i
		// L[i] = max(L[i], L[j] + 1) voi dk a[i] > a[j]
		vector<int> L(n, 1);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < i; j++) {
				if(a[i] > a[j]) {
					L[i] = max(L[i], L[j] + 1);
				}
			}
		}
		cout << *max_element(L.begin(), L.end()) << endl;
	}
}
