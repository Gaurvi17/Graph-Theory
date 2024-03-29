#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> g[N];
int vis[N];
int level[N];
void bfs(int source)
{
    queue<int>q;
    q.push(source);
    vis[source]=1;
    while(!q.empty())
    {
        int current_vertex=q.front();
        q.pop();
        cout<<current_vertex<<endl;
        for(int child: g[current_vertex])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child]=1;
                level[child]=level[current_vertex]+1;
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(1);
    return 0;
}