#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int>adj[],int node,vector<int>&disc,vector<int>&low,vector<int>&parent,vector<pair<int,int>>&bridge)
{
    static int  time=0;
    disc[node]=time;
    low[node]=time;
    time=time+1;

    vector<int>::iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++)
    {
        if(disc[*it]==-1)
        {
            parent[*it]=node;
            dfs(adj,*it,disc,low,parent,bridge);
            low[node]=min(low[node],low[*it]);
            if(low[*it]>disc[node])
            {
                bridge.push_back({node,*it});
            }

        }
        else if(*it!=parent[node])
        {
            low[node]=min(low[node],disc[*it]);
        }
    
    }


}

void findSCC_Tarjan(vector<int>adj[],int n)
{
    vector<int>disc(n,-1),low(n,-1),parent(n,-1);
    vector<pair<int,int>>bridge;
    
  
    for(int i=0;i<n;i++)
    {
        if(disc[i]==-1)
        {
            dfs(adj,i,disc,low,parent,bridge);
        }
    }
    cout<<"bridges are: "<<endl;
    vector<pair<int,int>>::iterator it;
    for(it=bridge.begin();it!=bridge.end();it++)
    {
        cout<<it->first<<"-> "<<it->second<<endl;
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<int>adj[n];
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        
    }
    findSCC_Tarjan(adj,n);
    return 0;
}