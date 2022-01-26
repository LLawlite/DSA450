#include <bits/stdc++.h>
using namespace std;
vector<bool>vis;
vector<int>in,out;
void DFS(vector<pair<int,int>>adj[],int node,int minSum,int start,int end)
{
    vis[node]=true;
    if (in[node]==0)
    {
        start=node;
    }
    if(out[node]==0)
    {
        end=node;
    }
    
    vector<pair<int,int>>:: iterator it;
    for ( it = adj[node].begin(); it !=adj[node].end(); it++)
    {
        if(!vis[it->first])
        {
            minSum=min(minSum,it->second);
            
            
            DFS(adj,it->first,minSum,start,end);
        }
    }
    
}


vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d)
{
   vis.resize(n+1,false);
   in.resize(n+1,0);
   out.resize(n+1,0);
   vector<pair<int,int>>adj[n+1];
   for (int i = 0; i < p; i++)
   {
       adj[a[i]].push_back({b[i],d[i]});
   }
   for (int i = 1; i <=n; i++)
   {
       out[i]=adj[i].size();
       for (int j = 0; j <adj[i].size(); j++)
       {
           in[adj[i][j].first]++;
       }
       
   }
   vector<vector<int>>ans;
   int componentCount=0;
   

   for (int i = 1; i <=n; i++)
   {
       int start=0,end=0,minSum=0;
       if(!vis[i])
       {
           minSum=adj[i][0].second;
           DFS(adj,i,minSum,start,end);
           ans[componentCount].push_back(start);
           ans[componentCount].push_back(end);
           ans[componentCount].push_back(minSum);
           componentCount++;
        
       }
   }
   
   

   return ans;

}
