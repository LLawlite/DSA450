#include <bits/stdc++.h>
using namespace std;
vector<int>dist;
vector<bool>vis;

int minDistance(int n)
{
    int mn=INT_MAX,vertex;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==false and dist[i]<=mn)
        {
            mn=dist[i];
            vertex=i;
        }
    }
    return vertex;
}
void dijkrats(vector<pair<int,int>>adj[],int n,int src)
{
    dist.resize(n,INT_MAX);
    dist[src]=0;
    vis.resize(n,false);
    for(int i=0;i<n-1;i++)
    {
        int u=minDistance(n);
        vis[u]=true;
        vector<pair<int,int>>:: iterator it;
        for(it=adj[u].begin();it!=adj[u].end();it++)
        {
            if(vis[it->first]==false and dist[u]!=INT_MAX and dist[u]+it->second<dist[it->first])
            {
                dist[it->first]=dist[u]+it->second;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<src<<" --> "<<i<<"  ->  "<<dist[i]<<endl;
    }
}

int main()
{
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>>adj[n];
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back({y,0});
        adj[y].push_back({x,1});///modify the graph so that we can make it to reach our detination .
    //1 represents the cost to change the direction of the edge
    }
    int src,dst;
    cout<<"Enter src and desination "<<endl;
    cin>>src>>dst;
    dijkrats(adj,n,src);
    return 0;

   

}