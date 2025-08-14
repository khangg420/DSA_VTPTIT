#include <bits/stdc++.h>
using namespace std;

// H�m t�m s? BDN nh? nh?t chia h?t cho n
string findBDN(int n) {
    queue<pair<string, int>> q;
    set<int> visited;

    q.push({"1", 1 % n});
    visited.insert(1 % n);

    while (!q.empty()) {
        pair<string, int> front = q.front(); q.pop();
		string num = front.first;
		int rem = front.second;

        if (rem == 0) return num;

        // T?o 2 s? m?i b?ng c�ch th�m '0' v� '1'
        int rem0 = (rem * 10) % n;
        if (!visited.count(rem0)) {
            q.push({num + "0", rem0});
            visited.insert(rem0);
        }

        int rem1 = (rem * 10 + 1) % n;
        if (!visited.count(rem1)) {
            q.push({num + "1", rem1});
            visited.insert(rem1);
        }
    }

    return ""; // Kh�ng bao gi? x?y ra v?i n < 1000
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << findBDN(n) << endl;
    }
    return 0;
}
