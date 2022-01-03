#include <bits/stdc++.h>
using namespace std;
 int n=4;
 //adjacency matrix with default graph
 int dist[10][10]={
     {0,20,42,25},
     {20,0,30,34},
     {42,30,0,10},
     {25,34,10,0}
 };
 
 //if all cities have been visited
 int VISITED_ALL=(1<<n)-1;
 int tsp(int mask,int pos)
 {
     //mask workks like a visited array like 1001 meam city 0 and 3 are visited and 1 and 2 are not.
     if(mask==VISITED_ALL)
     {
         return dist[pos][0];//return the distance from end to srcnode

     }
     int ans=INT_MAX;
     for(int city=0;city<n;city++)
     {
         if((mask&(1<<city))==0)//city not visited
         {
             int newAns=dist[pos][city]+tsp(mask|(1<<city),city);
             ans=min(ans,newAns);
         }
     }
     return ans;


 }
 int main()
 {
     cout<<tsp(1,0)<<endl;
     return 0;
 }