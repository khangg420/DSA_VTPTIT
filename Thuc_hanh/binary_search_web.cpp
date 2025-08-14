#include <bits/stdc++.h>
using namespace std;

bool BinarySearch(int a[], int n, int x) {
	int left = 0, right = n - 1;
	while(left <= right) {
		int mid = (left + right) / 2;
		if(a[mid] == x) {
			return true;
		}
		else if (a[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return false;
}

int pos(int a[], int n, int k) {
	int l = 0, r = n - 1;
	while(l <= r) {
		int m = (l + r) / 2;
		if(a[m] == k){
			return m + 1;
		}
		else if(a[m] < k) {
			l = m + 1;
		}
		else r = m - 1;
	}
	return -1;
}

int main() {
	int t; cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int a[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		if(pos(a, n, k) != -1) {
			cout << pos(a, n, k) << endl;
		}
		else 
			cout << "NO" << endl;
	}
}
