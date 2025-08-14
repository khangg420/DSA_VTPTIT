#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int m[500][500] = {0};
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> m[i][j];
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(m[i][j]) {
				cout << j << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
