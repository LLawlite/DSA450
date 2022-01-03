#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[], vector<bool> &vis, int node, stack<int> &s)
{
    vis[node] = true;

    vector<int>::iterator it;
    for (it = adj[node].begin(); it != adj[node].end(); it++)
    {
        if (!vis[*it])
        {
            dfs(adj, vis, *it, s);
        }
    }
    s.push(node);
}

vector<int> topoSort(int n, vector<int> adj[])
{
    vector<bool> vis(n, false);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(adj, vis, i, s);
        }
    }
    vector<int> ans;
    while (!s.empty())
    {

        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}