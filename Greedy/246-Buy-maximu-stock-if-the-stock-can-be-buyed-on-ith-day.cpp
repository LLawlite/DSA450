#include<bits/stdc++.h>
using namespace std;


int buyMaximumProducts(int n, int k, int price[])
{
    vector<pair<int,int>>arr;
    for (int i = 0; i < n; i++)
    {
        arr.push_back({price[i],i+1});
    }
    sort(arr.begin(),arr.end());
    int ans=0;
    int curr=0;
    for (int i = 0; i < n; i++)
    {
        if(curr+arr[i].first<=k)
        {
            ans+=arr[i].second;
            curr+=arr[i].first;
        }
        else
        {
            int remain=k-curr;
            ans+=curr/arr[i].first;
            break;
        }
        
    }
    

   
    return ans;
   
}
int main()
{
    int price[] = { 10, 7, 19 };
    int n = sizeof(price)/sizeof(price[0]);
    int k = 45;
 
    cout << buyMaximumProducts(n, k, price) << endl;
 
    return 0;
}