#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
void solve(Node*root,int sum,int len ,int &maxSum,int &maxlen)
{
    if(root==NULL)
    {
        if(maxlen<len)
        {
            maxlen=len;
            maxSum=sum;
        }
        else if(maxlen==len and maxSum<sum)
        {
            maxSum=sum;
        }
        return;
    }
    solve(root->left,sum+root->data,len+1,maxSum,maxlen);
    solve(root->right,sum+root->data,len+1,maxSum,maxlen);
}
int sumOfLongRootToLeafPath(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int maxSum=INT_MIN,maxlen=0;
    solve(root,0,0,maxSum,maxlen);
    return maxSum;
}