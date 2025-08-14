#include <bits/stdc++.h>
using namespace std;

int countBDN(int n) {
	queue<int> q;
	q.push(1);
	int cnt = 0;
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		if(cur > n) break;
		else {
			cnt++;
			q.push(cur * 10);
			q.push(cur * 10 + 1);
		}
	}
	return cnt;
}

int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		cout << countBDN(n) << endl;
	}
	return 0;
}
