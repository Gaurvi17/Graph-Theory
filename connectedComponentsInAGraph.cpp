#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> g[N];
bool vis[N];
vector<vector<int>>cc;
vector<int>ccc;
void dfs(int vertex)
{
    vis[vertex] =true;
    ccc.push_back(vertex);
    for(int child : g[vertex])
    {
        if(vis[child])
            continue;
        dfs(child);
    }
}

int main()
{
    int n,e,count=0;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) 
            continue;
        ccc.clear();
        dfs(i);
        cc.push_back(ccc);
        count++;
    }
    cout<<count<<endl;
    for(auto ccc:cc)
    {
        for(auto vertex:ccc)
            cout<<vertex<<" ";
        cout<<endl;
    }
    return 0;
}