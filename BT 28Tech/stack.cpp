#include <bits/stdc++.h>
#include <stack>
using namespace std;

//push
//pop
//top
//size
//empty

int main() {
//	stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	cout << st.top() << endl;
//	st.pop();	
	string s;
	getline(cin, s);
	stringstream ss(s);
	string token;
	stack<string> st;
	while(ss >> token) {
		st.push(token);
	}
	while(!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	return 0;
}
