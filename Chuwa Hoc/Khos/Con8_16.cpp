#include <bits/stdc++.h>
using namespace std;

string rotateLeft(string s) {
    string t = s;
    t[0] = s[3];  // a -> d
    t[1] = s[0];  // b -> a
    t[3] = s[4];  // d -> e
    t[4] = s[1];  // e -> b
    return t;
}

string rotateRight(string s) {
    string t = s;
    t[1] = s[4];  // b -> e
    t[2] = s[1];  // c -> b
    t[4] = s[5];  // e -> f
    t[5] = s[2];  // f -> c
    return t;
}

int bfs(string start, string goal) {
    queue<pair<string, int>> q;
    set<string> visited;
    q.push({start, 0});
    visited.insert(start);

    while (!q.empty()) {
        auto [state, dist] = q.front();
        q.pop();
        if (state == goal) return dist;

        string left = rotateLeft(state);
        if (!visited.count(left)) {
            visited.insert(left);
            q.push({left, dist + 1});
        }

        string right = rotateRight(state);
        if (!visited.count(right)) {
            visited.insert(right);
            q.push({right, dist + 1});
        }
    }
    return -1; // Không th? x?y ra trong bài này
}

int main() {
    string start = "", goal = "";
    for (int i = 0; i < 6; ++i) {
        int x;
        cin >> x;
        start += (x + '0');
    }
    for (int i = 0; i < 6; ++i) {
        int x;
        cin >> x;
        goal += (x + '0');
    }

    cout << bfs(start, goal) << endl;
    return 0;
}
