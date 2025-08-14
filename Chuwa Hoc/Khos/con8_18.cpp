#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    int t;
    cin>>t;
    while(t--){
        int r, c;
        cin>>r>>c;

        vector<vector<int>> a(r, vector<int>(c, 0));
        queue<pair<int, int>> q;
        vector<vector<int>> days(r, vector<int>(c, 0));

        for(int i = 0;i < r;i++){
            for(int j = 0;j < c;j++){
                cin>>a[i][j];
                if(a[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        
        while(q.size()){
            auto [x, y] = q.front();
            q.pop();
            for(int k = 0;k < 4;k++){
                int tx = x + dx[k];
                int ty = y + dy[k];
                if(tx < r && tx >= 0 && ty < c && ty >= 0 && a[tx][ty] == 1){
                    q.push({tx, ty});
                    a[tx][ty] = 2;
                    days[tx][ty] = days[x][y] + 1;
                }
            }
        }

        int ans = 0;
        bool ok = 1;

        for(int i = 0;i < r;i++){
            for(int j = 0;j < c;j++){
                ans = max(ans, days[i][j]);
                if(a[i][j] == 1){
                    ok = 0;
                    break;                    
                }
            }
        }
        if(ok){
            cout<<ans<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}
