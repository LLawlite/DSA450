#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>g,int node,vector<bool>&vis,string &ans)
{
    vis[node]=true;
    vector<int>::iterator it;
    for(it=g[node].begin();it!=g[node].end();it++)
    {
        if(!vis[*it])
        {
            dfs(g,*it,vis,ans);
        }
    }
    char ch='a'+node;
    ans=ans+ch;
}

string findOrder(string dict[], int n, int k)
{
    vector<vector<int>>graph(k);
    for(int i=0;i<n-1;i++)
    {
       string  w1=dict[i];
       string w2 =dict[i+1];

       for (int j = 0; j < min(w1.length(),w2.length()); j++)
       {
           if(w1[j]!=w2[j])
           {
               graph[w1[j]-'a'].push_back(w2[j]-'a');
               break;
           }
       }
       
        
    }
    vector<bool>vis(k,false);
    string ans="";
    for (int i = 0; i < k; i++)
    {
        if(!vis[i])
        {
            dfs(graph,i,vis,ans);
        }
    }
    
return ans;
}