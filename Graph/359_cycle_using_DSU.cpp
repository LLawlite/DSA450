#include <bits/stdc++.h>
using namespace std;
vector<int>parent;
int find(int v)
{
    if(parent[v]==-1)
    {
        return v;
    }
    return find(parent[v]);
}
void unionop(int a,int b)
{
    parent[find(a)]=find(b);
}

bool isCycle(vector<pair<int,int>>&adj)
{
  for (auto x: adj )
  {
      int a=find(x.first);
      int b=find(x.second);
      if(a==b)
      {
          return true;
      }
      unionop(a,b);
  }
  return false;
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>>adj;
    parent.resize(n+1,-1);
    for (int i = 0; i < e; i++)
    {
        int x,y;
        cin>>x>>y;
        adj.push_back({x,y});

    }
    cout<<isCycle(adj);

    
}