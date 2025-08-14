#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main() {
	int t; cin >> t;
	queue<int> q;
	while(t--) {
		string command;
		cin >> command;
		if(command == "PUSH") {
			int x; 
			cin >> x;
			q.push(x);
		}
		else if(command == "POP") {
			if(q.empty() == 0) {
				q.pop();	
			}
		}
		else if(command == "PRINTFRONT") {
			if(q.empty()) 
				cout << "NONE" << endl;
			else
				cout << q.front() << endl;
		}
	}
	return 0;
}
