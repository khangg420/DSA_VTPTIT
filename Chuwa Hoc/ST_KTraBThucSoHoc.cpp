#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		stack <char> st;
		bool ok = true;
		for(char x : s) {
			if(x == '(' || x == '+' || x == '-' || x == '*' || x == '/') {
				st.push(x);
			}
			else if(x == ')') {
				if(st.top() == '(' ) {
					ok = false;
					break;
				}
				else {
					while(st.top() != '(' ) {
						st.pop();
					}
					st.pop();
				}
			}
		}
		if(ok == false) 
			cout << "Yes" << endl;
		else 
			cout << "No" << endl;
	}
}
