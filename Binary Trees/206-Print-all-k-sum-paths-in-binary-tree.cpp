 #include <bits/stdc++.h>
 using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  int counter=0;

  void allPath(TreeNode*root,int k,vector<int>&path)
  {
      if(root==NULL)
      {
          return ;
      }
    path.push_back(root->val);
      allPath(root->left,k,path);
      allPath(root->right,k,path);

      int sum=0;
      for (int i = path.size()-1; i >=0; i--) //because we have to go downwards
      {
          sum+=path[i];
          if(sum==k)
          {
             counter++;
          }
      }
      path.pop_back();
      

  }
   int pathSum(TreeNode* root, int targetSum) {
       vector<int>path;
       allPath(root,targetSum,path);
       return counter;
        
    }