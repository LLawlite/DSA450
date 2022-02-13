#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
vector<int> leftView(Node *root)
{
   vector<int>ans;
   if(root==NULL)
   {
       return ans;
   }
   queue<Node*>q;
   q.push(root);
  
   while (!q.empty())
   {
       int n=q.size();
       for (int i = 0; i < n; i++)
       {
           Node*temp=q.front();
           q.pop();
           if(i==0)
           {
               ans.push_back(temp->data);
           }
           if(temp->left)
           {
               q.push(temp->left);
           }
           if(temp->right)
           {
               q.push(temp->right);
           }
       }
       
       
   }
   return ans;
}
