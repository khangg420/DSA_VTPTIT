#include <bits/stdc++.h>
using namespace std;

void recursion(int a[], int n){
    if(n == -1) return;
    cout << a[n] << " ";
    recursion(a, n-1);
}

int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        recursion(a, n-1);
        cout << "\n";
    }
}
