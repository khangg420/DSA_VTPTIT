#include <bits/stdc++.h>
using namespace std;

int minSwap(string s) {
	int balance = 0;
	int swap = 0;
	
	for(char c : s) {
		if(c == '['){
			balance++;
		} else {
			balance--;
			if(balance < 0) {
				swap++;
				balance = 1;
			}
		}
	}
	return swap * 2;
}

int main() {
	int t; cin >> t;
	while(t--) {
		string s;
		cin >> s;
		cout << minSwap(s) << endl;
	}
	return 0;
}
