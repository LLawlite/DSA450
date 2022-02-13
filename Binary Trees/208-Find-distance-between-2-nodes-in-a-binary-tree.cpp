#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
Node* LCA(Node*root ,int a,int b)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==a or root->data==b)
    {
        return root;
    }

    Node*leftLCA=LCA(root->left,a,b);
    Node*rightLCA=LCA(root->right,a,b);
    if(leftLCA and rightLCA)
    {
        return root;
    }
    if(leftLCA!=NULL)
    {
        return leftLCA;
    }
    return rightLCA;
}
int dist(Node*root,int a,int d)
{
    if(root==NULL)
    {
        return INT_MAX;
    }
    if(root->data==a)
    {
        return d;
    }
    int p=dist(root->left,a,d+1);
    int q=dist(root->right,a,d+1);
    return min(p,q);
}
int findDist(Node *root, int a, int b)
{
    Node*lca=LCA(root,a,b);
    int p=dist(lca,a,0);
    int q=dist(lca,b,0);
    return p+q;

}