#include <bits/stdc++.h>
using namespace std;
void dfs(int u,vector<int>&disc,vector<int>&low,stack<int>&s,vector<bool>&presentInStack,vector<int>adj[])
{
    static int time=0; //static, so that the time is trigred only once on the first call of the dfs.
    low[u]=time;
    disc[u]=time;
    time=time+1;
    s.push(u);
    presentInStack[u]=true;

    vector<int>:: iterator it;
    for(it=adj[u].begin();it!=adj[u].end();it++)
    {
        if(disc[*it]==-1)//if *it is not visited
        {
            dfs(*it,disc,low,s,presentInStack,adj);
            low[u]=min(low[u],low[*it]);
        }
        //differentiate backedge and cross edge
        else if(presentInStack[*it])//Back edge
        {
            low[u]=min(low[u],disc[*it]);
        }
    }
    if(low[u]==disc[u]) //if u is head of SCC.
    
    {
        cout<<"SCC is : ";
        while (s.top()!=u)
        {
            cout<<s.top()<<" ";
            presentInStack[s.top()]=false;
            s.pop();
        }
          cout<<s.top()<<" "<<endl;
            presentInStack[s.top()]=false;
            s.pop();
        
    }

}
void findSCC_Tarjan(vector<int>adj[],int n)
{
    vector<int>disc(n,-1),low(n,-1);
    vector<bool>presentInStack(n,false);
    stack<int>s;
    for(int i=0;i<n;i++)
    {
        if(disc[i]==-1)
        {
            dfs(i,disc,low,s,presentInStack,adj);
        }
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
        
    }
    findSCC_Tarjan(adj,n);
    return 0;
}