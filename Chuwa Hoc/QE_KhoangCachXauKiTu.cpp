#include<bits/stdc++.h>
using namespace std;

string s, e;

void BFS(set<string> &mySet)
{
    queue<string> q;
    q.push(s);
    int ans = 1;
    while(q.size())
    {
        ++ans;
        queue<string> tmp = q;
        while(tmp.size())
        {
            string u = tmp.front();
            tmp.pop();
            q.pop();
            for(int i = 0; i < u.size(); ++i)
            {
                char ori = u[i];
                for(char j = 'A'; j <= 'Z'; ++j)
                {
                    u[i] = j;
                    if(u == e)
                    {
                        cout << ans << endl;
                        return;
                    }
                    if(mySet.find(u) != mySet.end())
                    {
                        q.push(u);
                        mySet.erase(u);
                    }
                }
                u[i] = ori;
            }
        }
    }
}

int main()
{
    int t; cin >> t;
    string x;
    while(t--)
    {
    	int n;
        cin >> n >> s >> e;
        set<string> mySet;
        while(n--)
        {
            cin >> x;
            mySet.insert(x);
        }
        if(s == e)
        {
            cout << 1 << endl;
            continue;
        }
        BFS(mySet);
    }
    return 0;
}
