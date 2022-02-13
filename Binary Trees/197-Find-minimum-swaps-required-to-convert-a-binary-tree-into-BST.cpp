#include<bits/stdc++.h>
using namespace std;
 
// Inorder Traversal of Binary Tree
void inorder(int a[], std::vector<int> &v,
                        int n, int index)
{
    // if index is greater or equal to vector size
    if(index >= n)
        return;
    inorder(a, v, n, 2 * index + 1);
     
    // push elements in vector
    v.push_back(a[index]);
    inorder(a, v, n, 2 * index + 2);
}
 
// Function to find minimum swaps to sort an array
int minSwaps(std::vector<int> &v)
{
    int n=v.size();
    vector<pair<int,int>>p;
    for (int i = 0; i < n; i++)
    {
        p.push_back({v[i],i});
    }
    sort(p.begin(),p.end());
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        if(i==p[i].second)
        {
            continue;
        }
        else
        {
            ans++;
            swap(p[i],p[p[i].second]);
            i--;
        }
        
    }
    
    return ans;

}
 
// Driver code
int main()
{
    int a[] = { 5, 6, 7, 8, 9, 10, 11 };
    int n = sizeof(a) / sizeof(a[0]);
    std::vector<int> v;
    inorder(a, v, n, 0);
    cout << minSwaps(v) << endl;
}