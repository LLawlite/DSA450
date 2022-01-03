#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x,int y,int n,int m)
{
    if(x>=0 and x<n and y>=0 and y<m)
    {
        return true;
    }
    return false;
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    
    int n=image.size();
    int m=image[0].size();

    if(m==1 and n==1)
    {
        image[0][0]=newColor;
        return image;
    }
    int dx[]={0,1,0,-1};
    int dy[]={-1,0,1,0};
    int currColor=image[sr][sc];
    vector<vector<int>>vis(n,vector<int>(m,false));
    ///////---------------DFS------------------------////////////


    stack<pair<int,int>>s;
    s.push({sr,sc});
    while (!s.empty())
    {
        pair<int,int>temp=s.top();
        s.pop();
        int a=temp.first;
        int b=temp.second;
        vis[a][b]=true;
        image[a][b]=newColor;
        for(int i=0;i<4;i++)
        {
            int x=a+dx[i];
            int y=b+dy[i];

            if(isSafe(x,y,n,m) and !vis[x][y] and image[x][y]==currColor)
            {
                s.push({x,y});
            }
        }    
    }

    ///////----------------BFS------------------------///////////

    // queue<pair<int,int>>q;
    // q.push({sr,sc});
    // while (!q.empty())
    // {
    //     pair<int,int>temp=q.front();
    //     q.pop();
    //     int a=temp.first;
    //     int b=temp.second;
    //     vis[a][b]=true;
    //     image[a][b]=newColor;
    //     for(int i=0;i<4;i++)
    //     {
    //         int x=a+dx[i];
    //         int y=b+dy[i];

    //         if(isSafe(x,y,n,m) and !vis[x][y] and image[x][y]==currColor)
    //         {
    //             q.push({x,y});
    //         }
    //     }
    // }
    



return image;
    
    
}