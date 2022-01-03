#include <bits/stdc++.h>
using namespace std;
vector<int>color;
vector<bool>vis;
bool bipartite;
void colorGraph(vector<int>adj[],int node,int currColor)
{
    if(color[node]!=-1 and color[node]!=currColor)
    {
        bipartite=false;
        return ;
    }
    color[node]=currColor;
    if(vis[node])
    {
        return ;
    }
    vis[node]=true;
    for(auto i: adj[node])
    {
        colorGraph(adj,i,currColor xor 1);
    }

}

int main()
{
    bipartite=true;
    int n,e;
    cin>>n>>e;
    color.resize(n,-1);
    vis.resize(n,false);
    vector<int>adj[n];
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);

    }
    for (int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            colorGraph(adj,i,0);
        }
    }
    if(bipartite)
    {
        cout<<"Graph is biparete";
    }
    else{
        cout<<"Graph is not biparete";
    }
    


}