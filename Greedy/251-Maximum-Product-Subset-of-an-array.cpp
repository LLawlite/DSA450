#include <bits/stdc++.h>
using namespace std;
 
int maxProductSubset(int a[], int n)
{
    if(n==1)
    {
        return a[0];
    }

    int max_neg=INT_MIN;
    int zero=0;
    int neg=0;
    int prod=1;
    for (int i = 0; i < n; i++)
    {
        if(a[i]==0)
        {
            zero++;
            continue;
        }
        if(a[i]<0)
        {
            neg++;
            max_neg=max(max_neg,a[i]);
        }
        prod=prod*a[i];
    }
    if(zero==n)
    {
        return 0;
    }
    if(neg & 1) //negtaive is odd
    {
        if(neg==1 and zero>0 and neg+zero==n)
        {
            return 0;
        }
         prod=prod/max_neg;
    }
    return prod;
    
    
}
 
// Driver Code
int main()
{
    int a[] = {  -1, -1, -2, 4, 3  };
    int n = sizeof(a) / sizeof(a[0]);
    cout << maxProductSubset(a, n);
    return 0;
}