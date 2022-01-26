#include <bits/stdc++.h>
using namespace std;
int Maximize(int a[], int n)
{
    long long int ans=1;
    sort(a,a+n);
    for (int i = 0; i < n; i++)
    {
        ans*=a[i]*i;
    }
    // return ans%(1e9+7);
    
}