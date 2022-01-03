#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int>adj[],vector<bool>&vis,int node)
{
    vis[node]=true;
    vector<int>:: iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++)
    {
        if(!vis[*it])
        {
            dfs(adj,vis,*it);
        }
    }
}

bool connected(vector<int>adj[],int n)
{
    vector<bool>vis(n,false);
    int node=-1;
    for(int i=0;i<n;i++)
    {
        if(adj[i].size()>0)
        {
            node=i;
        }
    }
    if(node==-1)
    {
        return true;
    }
    dfs(adj,vis,node);
    for(int i=0;i<n;i++)
    {
        if(vis[i]==false and adj[i].size()>0)
        {
            return false;
        }
    }
    return true;
}
int find_Euler(vector<int>adj[],int n)
{
    if(!connected(adj,n))
    {
        return 0;
    }
    int odd=0;
    for(int i=0;i<n;i++)
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
    return (odd==0)?2:1;
}
void find_Euler_path(vector<int>adj[],int n)
{
    int res=find_Euler(adj,n);
    if(res==0)
    {
        cout<<"Not and eulriam graph"<<endl;
    }
    else if(res==1)
    {
        cout<<"semi Eulrian graph"<<endl;
    }
    else
    {
        cout<<"Eulrian graph"<<endl;
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
        adj[y].push_back(x);
    }
    find_Euler_path(adj,n);
    return 0;
}