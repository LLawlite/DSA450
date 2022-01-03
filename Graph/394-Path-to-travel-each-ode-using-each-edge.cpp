#include <bits/stdc++.h>
using namespace std;
unordered_map<int,vector<int>>adj;
vector<bool>vis;
vector<int>path;
void dfs(int node)
{
    vis[node]=true;
    path.push_back(node);
    vector<int>:: iterator it;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it);
        }
    }
   
}
bool connected_Graph(int n)
{
    vis.resize(n,false);
    int node=-1;
    for(int i=0;i<n;i++)
    {
        if(adj[i].size()>0)
        {
            node=i;
            break;
        }
    }
    if(node==-1)
    {
        return true;
    }
    dfs(node);
    for(int i=0;i<n;i++)
    {
        if(!vis[i] and adj[i].size()>0)
        {
            return false;
        }
    }
    return true;
}

int find_Euler(int n)
{
    if(!connected_Graph(n))
    {
        return 0;
    }
    int odd=0;
    for (int i = 0; i < n; i++)
    {
        if(adj[i].size() & 1)
        {
            odd+=1;
        }
    }
    if(odd>2)
    {
        return 0;
    }
   else 
    {
        for (int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                vis[i]=true;
                path.push_back(i);
            }
        }
        
        
    }
    return 1;
}
int main()
{
    int n,e;
    cin>>n>>e;
    for (int i = 0; i < e; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
 find_Euler(n);
    for (int i = 0; i < n; i++)
    {
        cout<<path[i]<<" ";
    }
    return 0;
    
    
}