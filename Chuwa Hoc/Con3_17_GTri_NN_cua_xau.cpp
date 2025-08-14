#include <bits/stdc++.h>
using namespace std;

int minValueAfterRemovals(string s, int k) {
    // �?m t?n su?t k� t?
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'A']++;
    }

    // T?o max heap
    priority_queue<int> pq;
    for (int f : freq) {
        if (f > 0) pq.push(f);
    }

    // Lo?i b? k k� t?
    while (k-- && !pq.empty()) {
        int top = pq.top(); pq.pop();
        top--;
        if (top > 0) pq.push(top);
    }

    // T�nh t?ng b�nh phuong t?n su?t c�n l?i
    long long res = 0;
    while (!pq.empty()) {
        int x = pq.top(); pq.pop();
        res += 1LL * x * x;
    }

    return res;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int k;
        string s;
        cin >> k >> s;
        cout << minValueAfterRemovals(s, k) << endl;
    }
    return 0;
}

