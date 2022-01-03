#include <bits/stdc++.h>
using namespace std;
bool isCycle_util(vector<int> adj[], vector<bool> &vis, int node)
{
    if (vis[node])
    {
        return true;
    }
    bool flag=false;
    vis[node] = true;
    vector<int>::iterator it;
    for (it = adj[node].begin(); it != adj[node].end(); it++)
    {
        flag=isCycle_util(adj, vis, *it);
        if (flag )
        {
            return true;
        }
       
    }
    return false;
}
bool isCycle(int n,vector<int>adj[])
{
    vector<bool> vis(n + 1, 0);
    bool flag=false;
    for (int i = 1; i <=n; i++)
    {
        vis[i]=true;
        vector<int>::iterator it;
        for(it=adj[i].begin();it!=adj[i].end();it++)
        {
            flag=isCycle_util(adj,vis,*it);
            if(flag){
                return true;
            }
        }
        vis[i]=false;
    }
    
return false;
}

void dfs(vector<int>adj[],vector<bool>&vis,stack<int>&s,int node)
{
    vis[node]=true;
    vector<int>:: iterator it;
    for(it=adj[node].begin(); it!=adj[node].end();it++)
    {
        if(!vis[*it])
        {
            dfs(adj,vis,s,*it);
        }
    }
    s.push(node);
}

bool canFinish(int n, vector<pair<int, int> >& prerequisites)
{
   vector<int>adj[n];
   int e=prerequisites.size();
   for(int i;i<e;i++)
   {
       int x=prerequisites[i].second;
       int y=prerequisites[i].first;
       adj[x].push_back(y);
   }
   if(isCycle(n,adj))
   {
       return false;
   }
   vector<bool>vis(n,false);
   stack<int>s;
   for(int i=0;i<n;i++)
   {
       if(!vis[i])
       {
           dfs(adj,vis,s,i);
       }
   }
   while (!s.empty())
   {
       vis[s.top()]=true;
       s.pop();
   }
   for(int i=0;i<n;i++)
   {
       if(!vis[i])
       {
           return false;
       }
   }
   return true;
}
int main()
{
    int n,e;
    cin >>n>>e;
    vector<pair<int,int>>adj;
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        adj.push_back({x,y});
    }
    cout<<canFinish(n,adj);
    return 0;
}