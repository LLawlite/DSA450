#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
void printSolution(vector<vector<int>>&dist)
{
    int V=dist.size();
    cout << "The following matrix shows the shortest "
            "distances"
            " between every pair of vertices \n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF"
                     << "     ";
            else
                cout << dist[i][j] << "     ";
        }
        cout << endl;
    }
}
 
void floydWarshall(vector<vector<int>>graph)
{
  int V=graph.size();
    vector<vector<int>>dist(V,vector<int>(V));
    
    for (int i = 0; i < graph.size(); i++)
        for (int j = 0; j < graph[i].size(); j++)
            dist[i][j] = graph[i][j];
  

    for (int k = 0; k < graph.size(); k++) {
        for (int i = 0; i < V; i++) {
            
            for (int j = 0; j < V; j++) {
                
             if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != INF
                        && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
  
    // Print the shortest distance matrix
    printSolution(dist);
}

int main()
{
    
      vector<vector<int>>graph = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };
  
    // Print the solution
    floydWarshall(graph);
    return 0;
}