#include <bits/stdc++.h>
using namespace std;
int dfs(vector<pair<int,int>> adj[], int src, int dst, int k, vector<vector<int>> &dp)
{
   if (src == dst)
   {
      return 0;
   }
   if (k < 0)
   {
      return INT_MAX;
   }
   if (dp[src][k] != -1)
   {
      return dp[src][k];
   }
   int ans = INT_MAX;
   vector<pair<int,int>>:: iterator it;
   for(it=adj[src].begin();it!=adj[src].end();it++)
   {
      int temp=dfs(adj,it->first,dst,k-1,dp);
      if(temp!=INT_MAX)
      {
         ans=min(ans,it->second+temp);
      }
   }
   return dp[src][k]=ans;
}

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
   vector<pair<int,int>> adj[n];
     for(auto it:flights){
            int src=it[0];
            int dest=it[1];
            int wt=it[2];
            adj[src].push_back(make_pair(dest,wt));
        }

      vector<vector<int>>dp(n,vector<int>(n,-1));
      int ans=dfs(adj,src,dst,k,dp);
      if(ans!=INT_MAX);
      {
         return ans;
      }  
      return -1;
   
}
