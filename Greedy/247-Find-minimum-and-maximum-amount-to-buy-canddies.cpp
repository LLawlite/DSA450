#include <bits/stdc++.h>
using namespace std;
int solve(int candies[],int n,int k)
{
       int res = 0;
    for (int i = 0; i < n; i++) {
       
        res += candies[i];

        
        n = n - k;
    }
    return res;
}

vector<int> candyStore(int candies[], int N, int K)
{
    sort(candies,candies+N);
    int mn=solve(candies,N,K);
    sort(candies,candies+N,greater<>());
    int mx=solve(candies,N,K);
    vector<int>ans;
    ans.push_back(mn);
    ans.push_back(mx);
    return ans;
   
    
}