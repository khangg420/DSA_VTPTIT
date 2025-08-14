#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		queue<int> q;
		while(n--) {
			int type; 
			cin >> type;
			if(type == 1) {
				cout << q.size() << endl;
			}
			else if(type == 2) {
				if(q.empty()) cout << "YES" << endl;
				else cout << "NO" << endl;
			}
			else if(type == 3) {
				int x;
				cin >> x;
				q.push(x);
			}
			else if(type == 4) {
				if(!q.empty()) q.pop();
			}
			else if(type == 5) {
				if(q.empty()) cout << -1 << endl;
				else cout << q.front() << endl;
			}
			else if(type == 6) {
				if(q.empty()) cout << -1 << endl;
				else cout << q.back() << endl;
			}
		}
	}
	return 0;
}
