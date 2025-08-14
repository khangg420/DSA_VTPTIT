#include <bits/stdc++.h>
using namespace std;

int calc(int a, int b, char c) {
	if(c == '+') return a + b;
	if(c == '-') return a - b;
	if(c == '*') return a * b;
	if(c == '/') {
		if(b == 0) return 0;
		else return a / b;
	}
}

int main() {
	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		stack<int> st;
		for(int i = 0; i < s.size(); i++) {
			if(isdigit(s[i])) {
				st.push(s[i] - '0');
			}
			else {
				int top1 = st.top(); st.pop();
				int top2 = st.top(); st.pop();
				st.push(calc(top2, top1, s[i]));
			}
		}
		cout << st.top() << endl;
	}
}

//int Postfix(const string& a) {
//	stack <int> st;
//	for(char ch : a) {
//		if(isdigit(ch)) {
//			st.push(ch - '0');
//		} else {
//			int b = st.top();
//			st.pop();
//			int a = st.top();
//			st.pop();
//			int res = 0;
//			switch (ch) {
//				case '+': res = a + b; break;
//				case '-': res = a - b; break;
//				case '*': res = a * b; break;
//				case '/': res = a / b; break;
//			}
//			st.push(res);
//		}
//	}
//	return st.top();
//}
//
//int main() {
//    int t; cin >> t;
//    cin.ignore(); // Bor dòng newline sau so T
//    while (t--) {
//        string a;
//        getline(cin, a);
//        cout << Postfix(a) << endl;
//    }
//    return 0;
//}

