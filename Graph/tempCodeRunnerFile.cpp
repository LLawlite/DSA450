#include <bits/stdc++.h>
using namespace std;
vector<int>inTime;
vector<int>outTime;
vector<bool>vis;
void dfs(vector<int>adj[],int node,int time,int par)
{
   
    inTime[node]=time++;
    vector<int>:: iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++)
    {
        if(*it!=par)
        {
            dfs(adj,*it, time,par);
        }
    }
    outTime[node]=time++;
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
    int time=1;
   
    inTime.resize(n+1);
    outTime.resize(n+1);
    vector<int>adj[n+1];
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(adj,1,time,0);
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int type,x,y;
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