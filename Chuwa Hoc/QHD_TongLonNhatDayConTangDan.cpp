#include <bits/stdc++.h>
using namespace std;

int maxIncreasingSubsequenceSum(vector<int>& a) {
    int n = a.size();
    vector<int> dp = a;

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << maxIncreasingSubsequenceSum(a) << endl;
    }
    return 0;
}

