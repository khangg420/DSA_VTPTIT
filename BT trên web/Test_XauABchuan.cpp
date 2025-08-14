#include <bits/stdc++.h>
using namespace std;

int n, k;
set<string> se;
void Try(string s, int cnt, int ok) {
	if(cnt == k)
		ok = 1;
	if(cnt > k)
		return;
	if(s.size() == n) {
		if(ok)
			se.insert(s);
		return;
	}
	if(s[s.size() - 1] == 'A')
		Try(s + 'A', cnt + 1, ok);
	else
		Try(s + 'A', 1, ok);
	Try(s + 'B', 0, ok);
	
}

int main() {
	cin >> n >> k;
	Try("", 0, 0);
	cout << se.size() << endl;
	for(auto it : se){
		cout << it << endl;
	}
	return 0;
}
