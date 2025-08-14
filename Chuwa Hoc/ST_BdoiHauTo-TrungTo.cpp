#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		string t; cin >> t;
		stack<string> st;
		for(auto x : t) {
			if(isalpha(x)) {
				st.push(string(1, x));
			}
			else {
				string top1 = st.top(); st.pop();
				string top2 = st.top(); st.pop();
				st.push("(" + top2 + string(1, x) + top1 + ")");
			}
		}
		cout << st.top() << endl;
	}
}
