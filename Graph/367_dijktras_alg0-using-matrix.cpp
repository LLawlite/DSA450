//Time complexity = (V^2)
#include <bits/stdc++.h>
using namespace std;
#define V 9
int minDistance(int dist[],bool sptSet[])
{
    int mn=INT_MAX,index;
    for (int i = 0; i < V; i++)
    {
        if(sptSet[i]==false && dist[i]<=mn)
        {
            index=i;
            mn=dist[i];

        }
    }
    return index;
    
}


void printSolution(int dist[],int parent[])
{
    cout <<"Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout  << i << " \t\t"<<dist[i]<<"\t and "<<parent[i]<<"-> "<<i<< endl;
}
void dijktras(int graph[V][V],int src)
{
    bool sptSet[V];
    int dis[V];
    int parent[V];
    for(int i=0;i<V;i++)
    {
        sptSet[i]=false;
        dis[i]=INT_MAX;
    }
    
    dis[src]=0;

    for(int i=0;i<V-1;i++)
    {
        int u=minDistance(dis,sptSet);
        sptSet[u]=true;

        for(int v=0;v<V;v++)
        {
            if(!sptSet[v] && graph[u][v]!=0  && dis[u]!=INT_MAX && dis[u]+graph[u][v]< dis[v])
            {
                dis[v]=dis[u]+graph[u][v];
                parent[v]=u;
            }
        }


    }
    printSolution(dis,parent);
}
int main()
{
       int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
 
    dijktras(graph, 0);
 
    return 0;
}