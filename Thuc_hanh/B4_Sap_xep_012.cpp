#include <bits/stdc++.h>
using namespace std;

void sapxep(vector<int> &a) {
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int i : a) {
        if (i == 0) cnt0++;
        else if (i == 1) cnt1++;
        else cnt2++;
    }
    int i = 0;
    while (cnt0--) a[i++] = 0;
    while (cnt1--) a[i++] = 1;
    while (cnt2--) a[i++] = 2;
}

int main() {
    int t; 
	cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sapxep(a);
        for (int i : a) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
