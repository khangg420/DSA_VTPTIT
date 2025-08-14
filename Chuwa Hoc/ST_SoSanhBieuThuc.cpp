#include <bits/stdc++.h> 
using namespace std;

void solve(string &s) {
	stack <int> st;
	
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == '(') {
			st.push(i);			// Dua chi so i tai vi tri chua dau '(' vao trong stack
		}
		if(s[i] == ')') {
			if(s[st.top() - 1] == '-') {	// KTra vi tri truoc dau '(' : Neu la dau tru thi trong ngoac doi dau
				// Vi tri i hien tai dang la vi tri cua dau ')'
				for(int j = st.top() + 1; j < i; j++) {
					
					if(s[j] == '-') s[j] = '+';
					else if(s[j] == '+') s[j] = '-';
				}
			}
			st.pop();
		}
	}
	// String res chua ketqua sau khi phá ngoac
	string res = "";
	for(int i = 0; i < s.length(); i++) {
		if(s[i] != '(' && s[i] != ')') {
			res += s[i];
		}
	}
	s = res;
}

int main() {
	int t; cin >> t;
	while(t--) {
		string p1, p2;
		cin >> p1 >> p2;
		solve(p1);
		solve(p2);
		cout << (p1 == p2 ? "YES" : "NO") << endl;
		cout << p1 << " " << p2 << endl;
	}
}
