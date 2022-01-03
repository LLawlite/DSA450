#include <bits/stdc++.h>
using namespace std;

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
    vector<int>res(n,-1);
    res[0]=0;
    vector<bool>color(n,false);
    int cn=0;
    for(int i=0;i<n;i++)
    {
        vector<int>:: iterator it;
        for(it=adj[i].begin();it!=adj[i].end();it++)
        {
            if(res[*it]!=-1)
            {
                color[res[*it]]=true;
            }

        }
        int cr;
        for(cr=0;cr<n;cr++)
        {
            if(color[cr]==false)
            {
                break;
            }
        }
        res[i]=cr;
        cn=max(cn,cr+1);
        for(it=adj[i].begin();it!=adj[i].end();it++)
        {
            if(res[*it]!=-1)
            {
                color[res[*it]]=false;
            }

        }

    }
    cout<<cn<<endl;
    return 0;
}