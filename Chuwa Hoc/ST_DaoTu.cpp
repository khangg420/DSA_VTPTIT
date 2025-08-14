#include <bits/stdc++.h>
using namespace std;

string daotu(string s) {
    stringstream ss(s);
    string word, res;
    while (ss >> word) {
        reverse(word.begin(), word.end()); // Ðao nguoc t?
        res += word + " "; // Thêm tu vào ketqua
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); 
    while(t--){
    	string s;
		getline(cin,s);
		cout << daotu(s) << endl; 
	} 
}
