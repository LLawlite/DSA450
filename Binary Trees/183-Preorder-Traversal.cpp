struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <bits/stdc++.h>
using namespace std;

vector<int> postorderTraversal(TreeNode *root)
{
   
    vector<int>ans;

    stack<TreeNode*>s;
    TreeNode*curr=root;
    while (curr!=NULL || !s.empty())
    {
        while (curr!=NULL)
        {
            if(curr->right)
            {
                s.push(curr->right);
            }
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        if(curr->right and curr->right==s.top())
        {
            s.pop();
            s.push(curr);
            curr=curr->right;
        }
        else
        {
            ans.push_back(curr->val);
            curr=NULL;
        }
        
        
    }
    

    return ans;
}