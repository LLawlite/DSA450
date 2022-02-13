#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left, * right;
};
int helper(Node *root){
       
       if(!root) return 0;
       if(root->left==nullptr and root->right==nullptr) return root->data;
       int left=helper(root->left);
       int right=helper(root->right);
       
       if(left==-1 or right==-1 or root->data!=left+right) return -1;
       return left+right+root->data;
   }
   
   bool isSumTree(Node* root)
   {
        // Your code here
        int ans = helper(root);
        if(ans==-1) return false;
        return true;
   }