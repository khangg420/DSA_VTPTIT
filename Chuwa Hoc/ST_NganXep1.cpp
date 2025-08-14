#include <bits/stdc++.h>
using namespace std;

int main() {
	string command;
	stack <int> st;
	while(cin >> command) {
		if(command == "push") {
			int n; cin >> n;
			st.push(n);
		}
		else if (command == "pop" && !st.empty()) {
			st.pop();
		}
		else if(command == "show") {
			if(st.empty()) 
				cout << "empty";
			else {
				vector<int> res;
				stack <int> tmp_st = st;
				while(!tmp_st.empty()) {
					int x = tmp_st.top();
					res.push_back(x);
					tmp_st.pop();
				}
				for(int i = res.size() - 1; i >= 0; i--){
					cout << res[i] << " ";
				}
			}
			cout << endl;
		}
	}
}
