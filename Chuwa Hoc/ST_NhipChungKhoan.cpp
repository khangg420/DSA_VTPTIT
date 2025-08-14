#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n + 1], b[n + 1];
        stack<int> st;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++){
            while(st.size() && a[i] >= a[st.top()]) st.pop();
            if(st.empty())
                b[i] = 0;
            else
                b[i] = st.top();
            st.push(i);
        }
        for(int i = 1; i <= n; i++)
            cout << i - b[i] << ' ';
        cout << endl;
    }
}
