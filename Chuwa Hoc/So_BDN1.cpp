#include <iostream>
#include <queue>
using namespace std;

// Ð?m s? BDN nh? hon ho?c b?ng N
int countBDN(long long N) {
    queue<long long> q;
    q.push(1);
    int count = 0;

    while (!q.empty()) {
        long long current = q.front(); q.pop();
        if (current > N) break;
        count++;

        q.push(current * 10);     // Thêm '0'
        q.push(current * 10 + 1); // Thêm '1'
    }

    return count;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long N;
        cin >> N;
        cout << countBDN(N) << endl;
    }
    return 0;
}
