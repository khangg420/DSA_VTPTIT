#include <bits/stdc++.h>
using namespace std;

//vector<pair<int,int>> edge;
//	Tao ra struct "canh" co 2 gia tri cap voi nhau
struct edge{
	int u, v;
};

int n, m;
int parent[1001], sz[1001];
vector<edge> canh;	// luu canh cua do thi

void make_set() {
	for(int i = 1; i <= n; i++) {
		parent[i] = i;
		sz[i] = 1;
	}
}

int find(int v) {
	if(v == parent[v])
		return v;
	return parent[v] = find(parent[v]);
}

bool Union(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b) return false;	// Khong the gop a, b vao voi nhau
	if(sz[a] < sz[b]) swap(a, b);
	parent[b] = a;
	sz[a] += sz[b];
	return true;
}

void input(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
//		edge e = edge(x, y);
		edge e;
		e.u = x; e.v = y;
		canh.push_back(e);
	}
}

int main() {
	int t; cin >> t;
	while(t--) {
		input();
		make_set();
		int ok = 0;
		for(int i = 0; i < m; i++) {
			edge e = canh[i];
			if(Union(e.u, e.v) == 0) {
				ok = 1;
				break;
			}
		}
		if(ok) 
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
