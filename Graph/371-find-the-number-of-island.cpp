#include <bits/stdc++.h>
using namespace std;
#define COL 501

bool isSafe(int i ,int j,int n,int m)
{
    if(i>=0 and j>=0 and i<n and j<n)
    {
        return true;
    }
    return false;
}
void DFS(int M[][COL], int row, int col,
         bool visited[][COL],int n,int m)
{
    
     int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
  
    
    visited[row][col] = true;
  
    
    for (int k = 0; k < 8; ++k)
        if (isSafe( row + rowNbr[k], col + colNbr[k],n,m) and M[row + rowNbr[k]][col + colNbr[k]] and !visited[row + rowNbr[k]][col + colNbr[k]])
            DFS(M, row + rowNbr[k], col + colNbr[k], visited,n,m);
}
int countIslands(int M[][COL], int n, int m)
{
     bool visited[n][COL];
    memset(visited, 0, sizeof(visited));
    int count = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
  
            // If a cell with value 1 is not
            if (M[i][j] && !visited[i][j]) {
                // visited yet, then new island found
                // Visit all cells in this island.
                DFS(M, i, j, visited,n,m);
  
                // and increment island count
                ++count;
            }
  
    return count;
}

int main()
{
    int n,m;
    cin>>n>>m;
    int graph[n][COL];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>graph[i][j];
        }
    }
    cout<<countIslands(graph,n,m);
    return 0;

}