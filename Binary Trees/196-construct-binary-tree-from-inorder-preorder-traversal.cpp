#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

int preIndex = 0;
Node *buildFinal(int in[], int pre[], int is, int ie)
{
    if (is > ie)
        return NULL;

    Node *root = new Node(pre[preIndex++]);
    int index;
    for (int i = is; i <= ie; i++)
    {
        if (in[i] == root->data)
        {
            index = i;
            break;
        }
    }
    root->left = buildFinal(in, pre, is, index - 1);
    root->right = buildFinal(in, pre, index + 1, ie);

    return root;
}
Node *buildTree(int in[], int pre[], int n)
{
    // Code here
    Node *root = buildFinal(in, pre, 0, n - 1);
    return root;
}