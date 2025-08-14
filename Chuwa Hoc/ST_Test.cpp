#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t; 
	while(t--){
		string str; cin>>str;
		stack <char> stk;
		bool ok = true;
		for(char x : str){
			if(x == '{' || x == '[' || x == '(') 
				stk.push(x);
			else if(x == '}'){
				if(stk.empty()) ok = false;
				else if(stk.top() == '{') stk.pop();
			}
			else if(x == ']'){
				if(stk.empty()) ok = false;
				else if(stk.top() == '[') stk.pop();
			}
			else if(x == ')'){
				if(stk.empty()) ok = false;
				else if(stk.top() == '(') stk.pop();
			}
		}
		if(stk.size() > 0)
			ok = false;
		if(ok)
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
	return 0;
}
