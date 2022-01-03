#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int>adj[],vector<bool>&vis,int node)
{
    
    vis[node]=true;
     cout<<node<<" ";
    vector<int>:: iterator it;
     for(it=adj[node].begin();it!=adj[node].end();it++)
     {
         if(!vis[*it])
         {
             dfs(adj,vis,*it);
         }
     }
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<int>adj[n+1];
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
   vector<bool>vis(n+1,false);
    dfs(adj,vis,1);
}