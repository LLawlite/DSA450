#include <bits/stdc++.h>
using namespace std;
bool isCycle_util(vector<int> adj[], vector<bool> &vis, int node)
{
    if (vis[node])
    {
        return true;
    }
    bool flag=false;
    vis[node] = true;
    vector<int>::iterator it;
    for (it = adj[node].begin(); it != adj[node].end(); it++)
    {
        flag=isCycle_util(adj, vis, *it);
        if (flag )
        {
            return true;
        }
       
    }
    return false;
}
bool isCycle(int n,vector<int>adj[])
{
    vector<bool> vis(n + 1, 0);
    bool flag=false;
    for (int i = 1; i <=n; i++)
    {
        vis[i]=true;
        vector<int>::iterator it;
        for(it=adj[i].begin();it!=adj[i].end();it++)
        {
            flag=isCycle_util(adj,vis,*it);
            if(flag){
                return true;
            }
        }
        vis[i]=false;
    }
    
return false;
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj[n + 1];
    
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> rec(n + 1, 0);
    cout << isCycle(n,adj);
}

// Complexity Analysis:
// Time Complexity: O(V+E).
// Time Complexity of this method is same as time complexity of DFS traversal which is O(V+E).
// Space Complexity: O(V).
// To store the visited and recursion stack O(V) space is needed.