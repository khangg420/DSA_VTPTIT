#include <bits/stdc++.h>
using namespace std;
#define ll = long long;

int n, c[105][105], X[100];
int visited[105];
int d = 0, ans = INT_MAX, cmin = INT_MAX;
// Cau hinh : X1, X2, X3 .. Xn,
// X[i] : So thu tu thanh pho thu i ma ng du lich di qua

void nhap() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> c[i][j];
			if(c[i][j] != 0) 
				cmin = min(cmin, c[i][j]);
		}
	}
	memset(visited, 0, sizeof(visited));
}
// Di tim X[i] : 
void Try(int i) {
	for(int j = 1; j <= n; j++) {
		if(visited[j] == 0){
			visited[j] = 1;
			X[i] = j;
			d += c[X[i - 1]][X[i]];
			if(i == n) {
				// Cap nhat ketqua
				ans = min(ans, d + c[X[n]][1]);
			}
			// Danh gia cân duoi
			else if (d + (n - i + 1) * cmin < ans) {
				Try(i + 1);
			}
			// Backtrack
			visited[j] = 0;
			d -= c[X[i - 1]][X[i]];
		}
	}
}

int main() {
	nhap();
	X[1] = 1;
	visited[1] = 1;
	Try(2);
	cout << ans << endl;
}
