#include <bits/stdc++.h>
using namespace std;

int N, K;

// Hàm ki?m tra có dúng m?t dãy liên ti?p K ký t? 'A'
bool isValid(const string& s) {
    int count = 0;
    for (int i = 0; i <= N - K; i++) {
        if (s.substr(i, K) == string(K, 'A')) {
            // Ki?m tra xem tru?c và sau do?n này có ph?i là 'A' không
            if ((i > 0 && s[i - 1] == 'A') || (i + K < N && s[i + K] == 'A'))
                continue;
            count++;
        }
    }
    return count == 1;
}

void count(string s, int pos, int &cnt) {
    if (pos == N) {
        if (isValid(s))
            cnt++;
        return;
    }
    count(s + "A", pos + 1, cnt);
    count(s + "B", pos + 1, cnt);
}

void generate(string s, int pos) {
    if (pos == N) {
        if (isValid(s))
            cout << s << endl;
        return;
    }
    generate(s + "A", pos + 1);
    generate(s + "B", pos + 1);
}

int main() {
    cin >> N >> K;
    int cnt = 0;
    count("", 0, cnt);
    cout << cnt << endl;
    generate("", 0);
    return 0;
}
