#include <bits/stdc++.h>
using namespace std;

const int MAX = 35;
int A, B, C;
char maze[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
int dist[MAX][MAX][MAX];

int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

struct Node {
    int x, y, z;
};

bool isValid(int x, int y, int z) {
    return (x >= 0 && x < A && y >= 0 && y < B && z >= 0 && z < C);
}

int bfs(Node start, Node end) {
    memset(visited, false, sizeof(visited));
    memset(dist, -1, sizeof(dist));

    queue<Node> q;
    q.push(start);
    visited[start.x][start.y][start.z] = true;
    dist[start.x][start.y][start.z] = 0;

    while (!q.empty()) {
        Node cur = q.front(); q.pop();
        if (cur.x == end.x && cur.y == end.y && cur.z == end.z)
            return dist[cur.x][cur.y][cur.z];

        for (int i = 0; i < 6; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int nz = cur.z + dz[i];

            if (isValid(nx, ny, nz) && !visited[nx][ny][nz] && maze[nx][ny][nz] != '#') {
                visited[nx][ny][nz] = true;
                dist[nx][ny][nz] = dist[cur.x][cur.y][cur.z] + 1;
                q.push({nx, ny, nz});
            }
        }
    }

    return -1; // không tìm du?c du?ng di
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> A >> B >> C;
        Node start, end;

        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                string row;
                cin >> row;
                for (int k = 0; k < C; k++) {
                    maze[i][j][k] = row[k];
                    if (maze[i][j][k] == 'S') start = {i, j, k};
                    if (maze[i][j][k] == 'E') end = {i, j, k};
                }
            }
        }

        cout << bfs(start, end) << endl;
    }
    return 0;
}
