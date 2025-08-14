#include <bits/stdc++.h>
using namespace std;

string BDN2(int n) {
	queue<string> q;
	q.push("1");
	while(!q.empty()) {
		string s = q.front();
		q.pop();
		
		long long num = stoll(s);
		if(num % n == 0) 
			return s;
		else {
			q.push(s + "0");
			q.push(s + "1");
		}
 	}
 	return "";		//Truong hop khong xay ra
}

int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		cout << BDN2(n) << endl;
	}
	return 0;
}
