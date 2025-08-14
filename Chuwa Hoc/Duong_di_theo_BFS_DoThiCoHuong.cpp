#include<bits/stdc++.h>
using namespace std;

int m,n,s,t;
vector<int> adj[1005];
int par[1005];
bool visited[1005];

void init(){
	cin >>m >> n>>s >>t;
	for(int i=0;i<1001;i++)adj[i].clear();
	memset(visited, 0, sizeof(visited));
	memset(par, 0, sizeof(par));
	for(int i=1; i<= n;i++){
		int x,y;
		cin >> x>> y;
		adj[x].push_back(y);
	}
}
void bfs(int u, int k){
	visited[u]= true;
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		int v= q.front();
		q.pop();
	
		for(int x:adj[v]){
			if(!visited[x]){
				par[x]=v;
				visited[x]=true;
				q.push(x);
			}
		}
	}
}
void slove(){
	bfs(s, 0);
	vector<int> path;
	if(!visited[t]) cout << "-1\n";
	else{
		while(s!=t){
			path.push_back(t);
			t=par[t];
		}

	path.push_back(s);
	reverse(path.begin(), path.end());
	for(int x:path) cout << x << " ";
	cout << endl;
}
}
int main(){
	int t; cin >> t;
	while(t--){
		init();
		slove();
	}
	return 0;
}
