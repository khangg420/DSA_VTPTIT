#include <bits/stdc++.h>
using namespace std;

long long BinaryToLongLong(string s){
    long long num = 0;
    int k = 0;
    for(int i = s.length() - 1; i >= 0; i--){
        num = num + ((s[i] - '0') * pow(2, k++)); 
    }
    return num;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        queue<string> q;
        q.push("1");
        vector<string> res;
        while(q.size()){
            string tmp = q.front();
            long long num = BinaryToLongLong(q.front());
            q.pop();
            if(num <= n){
                res.push_back(tmp);
                q.push(tmp + "0");
                q.push(tmp + "1");
            }
        }

        for(string c : res){
            cout << c << " ";
        }
        cout << endl;
    }
}
