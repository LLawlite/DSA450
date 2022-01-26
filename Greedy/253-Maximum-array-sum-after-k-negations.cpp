#include <bits/stdc++.h>
using namespace std;
long long int sum(long long int arr[], int n)
{
    long long int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += arr[i];
    }
    return ans;
}
long long int maximizeSum(long long int arr[], int n, int k)
{

    sort(arr, arr + n);
    int i = 0;
    while (k > 0 and i < n)
    {
        if (arr[i] < 0)
        {
            arr[i] = -arr[i];
            k--;
        }
        i++;
    }
    int mn = INT_MAX;
    if (k % 2 != 0)
    {
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < mn)
            {
                index = i;
                mn = arr[i];
            }
        }
        arr[index] = -arr[index];
    }

    return sum(arr, n);
}
int main()
{
}