#include <bits/stdc++.h>
using namespace std;


void topoSort(vector<pair<int,int>>adj[],int node,stack<int>&s,vector<bool>&vis)
{
    vis[node]=true;
    vector<pair<int,int>>:: iterator it;
    for ( it = adj[node].begin(); it !=adj[node].end(); it++)
    {
        if(!vis[it->first])
        {
            topoSort(adj,it->first,s,vis);
        }
    }
    s.push(node);
    
}
void solve(vector<pair<int,int>>adj[],int n,int src)
{
    vector<bool>vis(n,false);
    vector<int>dist(n,INT_MIN);
    stack<int>s;
    dist[src]=0;

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            topoSort(adj,i,s,vis);
        }
    }

    while (!s.empty())
    {
        int u=s.top();
        s.pop();
        vector<pair<int,int>>:: iterator it;
        for(it=adj[u].begin();it!=adj[u].end();it++)
        {
            if(dist[u]!=INT_MIN and dist[u]+it->second>dist[it->first])
            {
                dist[it->first]=dist[u]+it->second;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<0<<"-> "<<i<< " --> "<<dist[i]<<endl;
    }
    
}

int main()
{
     int n,e;
    cin>>n>>e;
    vector<pair<int,int>>adj[n];
    for(int i=0;i<e;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
       
    }
    solve(adj,n,1);
}
// 6 10
// 0 1 5
// 0 2 3
// 1 3 6
// 1 2 2
// 2 4 4
// 2 5 2
// 2 3 7
// 3 5 1
// 3 4 -1
// 4 5 -2