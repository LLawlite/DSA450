#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], vector<bool> &vis, int node)
{
    vis[node]=true;
    vector<int>::iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++)
    {
        if(!vis[*it])
        {
            dfs(adj,vis,*it);
        }
    }
    
}
int makeConnected(int n, vector<vector<int>> &connections)
{
    vector<int>adj[n];
    vector<bool>vis(n,false);
    int edges=connections.size();
    for(int i=0;i<edges;i++)
    {
        int a=connections[i][0];
        int b=connections[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int components=0;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==false)
        {
            components++;
            dfs(adj,vis,i);
        }
    }
    int rebudantEdge=edges-((n-1)-(components-1));
    if(rebudantEdge>=components-1)
    {
        return components-1;
    }
   return -1;
    


}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> connection(n, vector<int>(2));
    for (int i = 0; i < e; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> connection[i][j];
        }
    }
    cout << makeConnected(n, connection);
}