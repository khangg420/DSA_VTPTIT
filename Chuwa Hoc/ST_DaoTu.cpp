#include <bits/stdc++.h>
using namespace std;

string daotu(string s) {
    stringstream ss(s);
    string word, res;
    while (ss >> word) {
        reverse(word.begin(), word.end()); // �ao nguoc t?
        res += word + " "; // Th�m tu v�o ketqua
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
