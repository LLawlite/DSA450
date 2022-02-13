#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root==p || root==q)
    {
        return root;
    }
    TreeNode* leftLCA=lowestCommonAncestor(root->left,p,q);
    TreeNode* rightLCA=lowestCommonAncestor(root->right,p,q);

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