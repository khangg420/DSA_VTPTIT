#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> b = a;
        sort(b.begin(), b.end());

        int l = 0, r = n - 1;
        while (l < n && a[l] == b[l]) l++;
        while (r >= 0 && a[r] == b[r]) r--;

        // Neu mang da sap (a == b) thì không can sap xep gi => in ra 1 1 hoac co the khong can sap
        if (l > r) cout << "1 1" << endl;
        else cout << l + 1 << " " << r + 1 << endl; 
    }
    return 0;
}

