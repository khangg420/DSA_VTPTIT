#include <bits/stdc++.h>
using namespace std;

int a[6], x[6], calc[6], check[6], res;	

bool out() {
	long long tmp;
	// Tinh toan gia tri ban dau
	// 1 2 3 tuong ung voi cac dau "+", "-", "*"
	if(calc[1] == 1) tmp = a[x[1]] + a[x[2]];
	if(calc[1] == 2) tmp = a[x[1]] - a[x[2]];
	if(calc[1] == 3) tmp = a[x[1]] * a[x[2]];
	// Duyet qua cac phan tu con lai va thuc hien phep tinh tuong ung
	for (int i = 3; i <= 5; i++) {
		if(calc[i-1] == 1) tmp += a[x[i]];
		if(calc[i-1] == 2) tmp -= a[x[i]];
		if(calc[i-1] == 3) tmp *= a[x[i]];
	}
	return tmp == 23;
}

void Try2(int i) {
	for (int j = 1; j <= 3; j++) {
		calc[i] = j;
		if (i == 4) {
			if(out() == 1) res = 1;
		}
		else Try2(i + 1);
	}
}

void Try(int i) {
	for(int j = 1; j <= 5; j++) {
		if (!check[j]) {
			check[j] = 1;
			x[i] = j;
			if(i == 5) {
				Try2(1);
			} 
			else {
				Try(i + 1);
			}
			check[j] = 0;
		}
	}
}

int main() {
	int t; cin >> t;
	while(t--) {
		res = 0;
		for (int i = 1; i <= 5; i++) cin >> a[i];
		Try(1);
		if(res == 0) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}
