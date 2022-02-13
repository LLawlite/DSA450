#include <bits/stdc++.h>
using namespace std;
int checkMirrorTree(int n, int e, int A[], int B[])
{
    map<int,stack<int>>m;
    for (int i = 0; i < 2*e-1; i=i+2)
    {
        m[A[i]].push(A[i+1]);
    }
    for (int i = 0; i < 2*e-1; i=i+2)
    {
        if(m[B[i]].top()!=B[i+1])
        {
            return 0;
        }
    }
    return 1;
    
    
}