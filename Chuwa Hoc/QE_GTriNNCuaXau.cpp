#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int k, x;
        string s;
        cin >> k >> s;
        long long n = 0;
        map<char, int> m;
        priority_queue<int> q;
        for (int i = 0; i < s.size(); i++)
            m[s[i]]++;
        for (auto i : m)
            q.push(i.second);
        while (k--)
        {
            x = q.top();
            q.pop();
            q.push(x - 1);
        }
        while (q.size())
        {
            n += q.top() * q.top();
            q.pop();
		}
        cout << n << endl;
    }
}
