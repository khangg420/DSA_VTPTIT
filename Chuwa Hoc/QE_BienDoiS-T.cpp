#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int S, T;
		cin >> S >> T;
		queue<pair<int, int>> q;
		q.push({S, 0});
		
		while(1) {
			pair<int, int> tmp = q.front();
			int value = tmp.first;
			int way = tmp.second;
			q.pop();
			if(value == T) {
				cout << way << endl;
				break;
			}
			if(value * 2 > 0) {
				q.push({value * 2, way + 1});
			}
			if(value - 1 > 0) {
				q.push({value - 1, way + 1});
			}
		}
	}
}
