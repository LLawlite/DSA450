#include <bits/stdc++.h>
using namespace std;
vector<int>inTime;
vector<int>outTime;
vector<bool>vis;
int timer=1;
void dfs(vector<int>adj[],int node,int par)
{
   vis[node]=true;
    inTime[node]=timer++;
    vector<int>:: iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++)
    {
        if(!vis[*it])
        {
            dfs(adj,*it,par); 
        }
    }
    outTime[node]=timer++;
}
bool isSubtree(int x,int y)
{
    if (inTime[x]>inTime[y] and outTime[x]<outTime[y])
    {
        return true;
    }
    return false;
    
}

int main()
{
    int n;
    cin>>n;
    timer=1;
   
    inTime.resize(n+1,0);
    outTime.resize(n+1,0);
    vis.resize(n+1,false);
    vector<int>adj[n+1];
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(adj,1,0);
   
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int type,x,y;
        cin>>type>>x>>y;
        if(!isSubtree(x,y) and !isSubtree(y,x))
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(type==0)
        {
            if(isSubtree(y,x))
            {
                cout<<"Yes"<<endl;

            }
            else
            {
                cout<<"No"<<endl;
            }
            
        }
        else if(type==1)
        {
              if(isSubtree(x,y))
            {
                cout<<"Yes"<<endl;

            }
            else
            {
                cout<<"No"<<endl;
            }
        }
       
        
        
    }
return 0;
}