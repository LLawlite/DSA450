#include <bits/stdc++.h>
using namespace std;
void DFS1(vector<int>adj[],int node,stack<int>&s,vector<bool>&vis)
{
    vis[node]=true;
    vector<int>:: iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++)
    {
        if(!vis[*it])
        {
             DFS1(adj,*it,s,vis);
        }
       
    }
    s.push(node);
}
void reverse(vector<int>adj[],vector<int>rev[],int n)
{
    for(int i=0;i<n;i++)
    {
        vector<int>:: iterator it;
        for(it=adj[i].begin();it!=adj[i].end();it++)
        {
            rev[*it].push_back(i);
        }
    }
    
}

void DFS2(vector<int>rev[],int node, vector<bool>&vis)
{
    cout<<node<<" ";
    vis[node]=true;
    vector<int>::iterator it;
    for(it=rev[node].begin();it!=rev[node].end();it++)
    {
        if(!vis[*it])
        {
            DFS2(rev,*it,vis);
        }
    }
}
void find_SCC(vector<int>adj[],vector<int>rev[],int n)
{
    vector<bool>vis(n,false);
    stack<int>s;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            DFS1(adj,i,s,vis);
        }
    }
    reverse(adj,rev,n);
    for (int i = 0; i < n; i++)
    {
        vis[i]=false;
    }
    cout<<"Strongly connected components are: "<<endl;
    while (!s.empty())
    {
        int curr=s.top();
        s.pop();
        if(!vis[curr])
        {
            DFS2(rev,curr,vis);
            cout<<endl;
        }
    }
    
    
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<int>adj[n];
    vector<int>rev[n];
    for (int i = 0; i < e; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    find_SCC(adj,rev,n);
    
}