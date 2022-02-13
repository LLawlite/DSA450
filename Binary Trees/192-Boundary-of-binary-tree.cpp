#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
vector<int>ans;
void left(Node*root)
{
    if(root==NULL)
    {
        return ;
    }
    if(root->left)
    
    {
        ans.push_back(root->data);
        left(root->left);
    }
    else if(root->right)
    {
        ans.push_back(root->data);
        left(root->right);
    }
}
void leaf(Node*root)
{
   if(root==NULL)
   {
       return ;
   }
        leaf(root->left);
        if(root->left==NULL and root->right==NULL)
        {
            ans.push_back(root->data);
        }
        leaf(root->right);
   
}
void right(Node*root)

{
    if(root==NULL)
    {
        return ;
    }
    if(root->right)
    {
        right(root->right);
        ans.push_back(root->data);
    }
    else if(root->left)
    {
        right(root->left);
        ans.push_back(root->data);
    }
}

vector<int> boundary(Node *root)
{
      ans.push_back(root->data);
         left(root->left);
         leaf(root->left);
         leaf(root->right);
         right(root->right);
        return ans;
}
int main()
{
    // Let us construct the tree given in the above diagram
    struct Node *root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);

    vector<int> ans = boundary(root);
    cout << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}