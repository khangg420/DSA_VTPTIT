#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int S, D;
		cin >> S >> D;
		if(S > D * 9) {
			cout << -1 << endl;
			continue;
		}
		
		string res = "";
		for(int i = 0; i < D; i++){
			for(int d = (i == 0 ? 1 : 0); d <= 9; d++) {
				if(S - d <= (D - i - 1) * 9 && S - d >= 0) {
					res += char(d + '0');
					S = S - d;
					break;
				}
			}
		}
		
		cout << res << endl;
	}
}
