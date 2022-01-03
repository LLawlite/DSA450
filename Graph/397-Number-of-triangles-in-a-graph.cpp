#include <bits/stdc++.h>
using namespace std;
#define V 4
int countTriangle(int graph[V][V],
                  bool isDirected)
{
    int count=0;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            for (int k = 0; k < V; k++)
            {
                if(graph[i][j] and graph[j][k] and graph[k][i])
                {
                    count++;
                }
            }
            
        }
        
    }
    isDirected?count/=3:count/=6;
    return count;
    
}

int main()
{
    // Create adjacency matrix
    // of an undirected graph
    int graph[][V] = { {0, 1, 1, 0},
                       {1, 0, 1, 1},
                       {1, 1, 0, 1},
                       {0, 1, 1, 0}
                     };
 
    // Create adjacency matrix
    // of a directed graph
    int digraph[][V] = { {0, 0, 1, 0},
                        {1, 0, 0, 1},
                        {0, 1, 0, 0},
                        {0, 0, 1, 0}
                       };
 
    cout << "The Number of triangles in undirected graph : "
         << countTriangle(graph, false);
    cout << "\n\nThe Number of triangles in directed graph : "
         << countTriangle(digraph, true);
 
    return 0;
}