#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>>ans;
    if(root==NULL)
    {
        return ans;
    }
    queue<TreeNode*>q;
    vector<int>arr;
    q.push(root);
    bool left=true;
    while (!q.empty())
    {
        int n=q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
            arr.push_back(temp->val);
        }
        if(left)
        {
            left=false;
            ans.push_back(arr);
        }
        else
        {
            left=true;
            reverse(arr.begin(),arr.end());
            ans.push_back(arr);
        }
        arr.clear();
        
    }
    return ans;
}