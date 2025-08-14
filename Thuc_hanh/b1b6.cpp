#include <bits/stdc++.h>
using namespace std;

int BinarySearch (int a[], int n, int x) {
	int l = 0, r = n - 1;
	while (l <= r) {
		int m = l + (r - l) / 2;
		if(a[m] == x) {
			return 1;
		}
		else if(a[m] < x) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	return -1;
}

int main() {
	int t;
	cin >> t;
	cin.ignore();
	while(t--) {
		int n, x;
		cin >> n >> x;
		int a[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		
		if (BinarySearch (a, n, x) == 1)
			cout << "1" << endl;
		else 
			cout << "-1" << endl;
	}
	return 0;
}
