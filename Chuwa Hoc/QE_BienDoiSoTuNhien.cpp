#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		queue<pair<int, int>> q;
		q.push({n, 0});
		
		while(1) {
			pair<int, int> tmp = q.front();
			int value = tmp.first;
			int way = tmp.second;
			q.pop();
			if(value == 1) {
				cout << way << endl;
				break;
			}
			for(int i = 2; i <= sqrt(value); i++) {
				if(value % i == 0) {
					int mx = max(i, value / i);
					q.push({mx, way + 1});
				}
			}
			if(value - 1 >= 0) {
				q.push({value - 1, way + 1});
			}
		}
	}
	
	return 0;
}
