#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
int find(int v)
{
    if (parent[v] == -1)
    {
        return v;
    }
    return find(parent[v]);
}
void unite(int a, int b)
{
    parent[find(a)] = find(b);
}
int kruskal(vector<vector<int>> &adj)
{
    int ans = 0;
    for (auto x : adj)
    {
        int w = x[0];
        int a = x[1];
        int b = x[2];
        if (find(a) != find(b))
        {

            ans = ans + w;
            unite(a, b);
        }
    }
    return ans;
}
int main()
{
    int n, e;
    vector<vector<int>> adj;
    cin >> n >> e;
    parent.resize(n + 1, -1);
    for (int i = 0; i < e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj.push_back({w, x, y});
    }
    sort(adj.begin(), adj.end());
    cout << kruskal(adj);
}
// Time Complexity: O(ElogE) or O(ElogV). Sorting of edges takes O(ELogE) time.
// After sorting, we iterate through all edges and apply the find-union algorithm.
// The find and union operations can take at most O(LogV) time. 
//So overall complexity is O(ELogE + ELogV) time.
// The value of E can be at most O(V2), so O(LogV) is O(LogE) the same.
// Therefore, the overall time complexity is O(ElogE) or O(ElogV)