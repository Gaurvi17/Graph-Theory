#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> g[N];
bool vis[N];
void dfs(int vertex)
{
    /** Take action on vertex after entering the vertex **/
    cout<<vertex<<endl;
    vis[vertex] =true;
    for(int child : g[vertex])
    {
        /** Take action on child before entering the child node **/
        if(vis[child])
            continue;
        dfs(child);
        /** Take action on child after entering the child node **/
    }
    /** Take action on vertex before exiting the vertex **/
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
    dfs(1);
    return 0;
}