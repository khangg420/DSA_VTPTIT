#include <bits/stdc++.h>
using namespace std;
#define ll long long

map<char, int> mp;
void init() {
	mp['^'] = 3;
	mp['*'] = 2; mp['/'] = 2;
	mp['+'] = 1; mp['-'] = 1;
}

int calc(int a, int b, char c) {
	if(c == '+') return a + b;
	if(c == '-') return a - b;
	if(c == '*') return a * b;
	if(c == '/') {
		if(b == 0) return 0;
		else return a / b;
	}
}

string inftoPost(string s) {
	string res = "";
	stack<char> st;
	for(auto x : s) {
		if(x == '(') {
			st.push(x);
		}
		else if(x == ')') {
			while(!st.empty() && st.top() != '(') {
				res += st.top();
				st.pop();
			}
			if(!st.empty()) {
				st.pop();
			}
		}
		else if(isdigit(x)) {
			res += x;
		}
		else {
			// 100#99#22
			if(isdigit(res[res.size() - 1])) res += '#';
			
			while(!st.empty() && st.top() != '(' && mp[st.top()] >= mp[x]) {
				res += st.top();
				st.pop();
			}
			st.push(x);
		}
	}
	while(!st.empty()) {
		res += st.top();
		st.pop();
	}
	return res;
}

int postValue(string s) {
	stack<int> st;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '#') {
			long long tmp = 0;
			while(i < s.size() && isdigit(s[i])) {
				tmp = 10 * tmp + (int)(s[i] - '0');
				i++;
			}
			cout << tmp << " ";
			if(s[i] != '#') i--;
			
			st.push(tmp);
		}
		else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
			int top1 = st.top(); st.pop();
			int top2 = st.top(); st.pop();
			st.push(calc(top2, top1, s[i]));
		}
	}
	return st.top();
}

int main() {
	init();
	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		string tmp = inftoPost(s);
		cout << inftoPost(s) << endl;
		cout << postValue(tmp) << endl;
	}
}
