#include <bits/stdc++.h> 
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		stack <int> st;
		int mx = 0;
		// Moc ban dau
		st.push(-1);
		
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == '(') {
				st.push(i);
			}
			else {
				st.pop();
				if(!st.empty()) {
					mx = max(mx, i - st.top());
				}
				else {
					st.push(i); // cap nhat moc moi
				}
			}
		}
		cout << mx << endl;
	}
	return 0;
}
