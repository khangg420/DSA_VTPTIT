#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> A;
vector<vector<int>> res;
vector<int> current;

void Try(int i, int sum) {
    if (sum == K) {
        res.push_back(current);
        return;
    }
    for (int j = i; j < N; j++) {
        if (sum + A[j] <= K) {
            current.push_back(A[j]);
            Try(j + 1, sum + A[j]);
            current.pop_back();
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> N >> K;
        A.resize(N);
        for (int i = 0; i < N; i++) cin >> A[i];

        // Sap xep dam bao ket qua theo dung thu tu tu dien
        sort(A.begin(), A.end());

        res.clear();
        current.clear();
        Try(0, 0);

        if (res.empty()) {
            cout << -1 << endl;
        } else {
            for (auto vec : res) {
                cout << "[";
                for (size_t i = 0; i < vec.size(); i++) {
                    cout << vec[i];
                    if (i != vec.size() - 1) cout << " ";
                }
                cout << "] ";
            }
            cout << endl;
        }
    }
    return 0;
}
