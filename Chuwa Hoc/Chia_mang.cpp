#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
    	int n, k;
    	cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int sumAll = 0;
        for (int num : a) sumAll += num;

        sort(a.begin(), a.end());

        int sumK_min = 0, sumK_max = 0;
        for (int i = 0; i < k; i++) sumK_min += a[i];
        for (int i = n - k; i < n; i++) sumK_max += a[i];
        
        int res1 = abs(sumAll - 2 * sumK_min);
        int res2 = abs(sumAll - 2 * sumK_max);

        cout << res1 << " " << res2 << endl;
    }

    return 0;
}

