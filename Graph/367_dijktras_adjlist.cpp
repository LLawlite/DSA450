#include <bits/stdc++.h>
using namespace std;
int minDistance(vector<int>&dist,vector<bool>&spt)
{
    int mn=INT_MAX,index;
    for (int i = 0; i < dist.size(); i++)
    {
        if(spt[i]==false and dist[i]<=mn)
        {
            index=i;
            mn=dist[i];
        }
    }
    return index;
    
}
void dijkrats(vector<pair<int,int>>adj[],int src,int n)
{
    vector<int>dist(n,INT_MAX);
    dist[src]=0;
    vector<bool>spt(n,0);
    for(int i=0;i<n-1;i++)
    {
        int u=minDistance(dist,spt);
        spt[u]=true;
        vector<pair<int,int>>::iterator it;
        for(it=adj[u].begin();it!=adj[u].end();it++)
        {
            if(spt[it->first]==false and dist[u]!=INT_MAX and dist[u]+it->second<dist[it->first] )
            {
                dist[it->first]=dist[u]+it->second;
            }
        }
        
    }
    for(int i=0;i<n;i++)
    {
        cout<<"0 --> "<<i<<"--> "<<dist[i]<<endl;
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
        adj[y].push_back({x,w});
    }
    dijkrats(adj,0,n);
return 0;
}