#include <bits/stdc++.h>
using namespace std;
// struct Node
// {
//     int data;
//     Node *left, *right;

//     Node(int data)
//     {
//         this->data = data;
//         this->left = this->right = nullptr;
//     }
// };
// //////////////////////////////// Method 1 ////////////////////////////////////////////
// /////////////////////////////// Time complexity O(N^2)///////////////////////////////
// int clackHeight(struct Node* root)
// {
//     if(root==NULL)
//     {
//         return 0;

//     }
//     return max(clackHeight(root->left),clackHeight(root->right))+1;

// }
// int diameter(struct Node* root) {
//     if(root==NULL)
//     {
//         return 0;
        
//     }
// int leftHeight=clackHeight(root->left);
//     int rightHeight=clackHeight(root->right);
//     int currDiameter=leftHeight+rightHeight+1;
//     int leftDiameter=diameter(root->left);
//     int rightDiameter=diameter(root->right);
//     return max(currDiameter,max(leftDiameter,rightDiameter));
// }


// /////////////////////////////////// Method 2 ///////////////////////////////////
// //////////////////////////// Time Complexity O(N) ///////////////////////////////

// int diameter(struct Node* root, int *height) {
//     if(root==NULL)
//     {
//         *height=0;

//         return 0;
        
//     }
//     int lh=0;
//     int rh=0;

//     int ldiameter=diameter(root->left,&lh);
//     int rdiameter=diameter(root->right,&rh);

//     int currDiameter=rh+lh+1;
//     *height=max(lh,rh)+1;
//     return max(currDiameter,max(ldiameter,rdiameter));

// }

//////////////////////////////////////// Method 3/////////////////////////////////
 struct TreeNode {
     int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
int diameter = 0;
    int getHeight(TreeNode* root){
        if(root==NULL)
            return 0;
        
        //get height of left & right subtree
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        
        //diamter of tree is : heigh of left subtree + height of right subtree
        diameter = max(diameter , leftHeight + rightHeight );
        
        //this height value is used by upper node
        return max(leftHeight ,rightHeight)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        getHeight(root);
        return diameter;
    }

    int main()
    {
        TreeNode*root=new TreeNode(5);
        root->left=new TreeNode(4);
        root->left->left=new TreeNode(3);
        root->left->left->left=new TreeNode(1);
        root->left->right=new TreeNode(0);
        root->right=new TreeNode(10);
        root->right->left=new TreeNode(11);
        root->right->right=new TreeNode(23);
        root->right->right->right=new TreeNode(45);
       cout<< diameterOfBinaryTree(root);
        
    }