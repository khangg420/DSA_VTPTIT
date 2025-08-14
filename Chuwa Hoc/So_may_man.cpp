#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int minTotal = 1e9;
		int bestA = -1, bestB = -1;
		
		for(int b = 0; b <= n / 7; b++) {
			int re = n - 7*b;
			if(re >= 0 && re % 4 == 0) {
				int a = re / 4;
				if(a + b < minTotal || (a + b == minTotal && a > bestA)) {
					minTotal = a + b;
					bestA = a;
					bestB = b;
				}
			}
		}
		if(bestA == -1) {
			cout << -1 << endl;
		} else {
			string res(bestA, '4');
			res += string(bestB, '7');
			cout << res << endl;
		}
	}
}
