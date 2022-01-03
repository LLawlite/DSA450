#include <bits/stdc++.h>
using namespace std;

bool Solve(vector<pair<int,int>>adj[],int k,int node,vector<bool>&vis)
{
    if(k<=0)
    {
        return true;
    }
    vector<pair<int,int>>:: iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++)
    {
        if (!vis[it->first])
        {
            vis[it->first]=true;
            if(Solve(adj,k-it->second,it->first,vis))
            {
                return true;
            }
            vis[it->first]=false;
        }
        
    }
return false;
}
 int main()
 {
     int n,e;
     cin>>n>>e;
     cout<<"Enter the value of k"<<endl;
     int k;
     cin>>k;
    vector<bool>vis(n,false);
     vector<pair<int,int>>adj[n];
    for(int i=0;i<e;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
       
    }
    cout<<Solve(adj,k,0,vis);
    return 0;
 }