#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
vector <Node*> nodes;

   void inorder(Node *head) {
       if(head == NULL)  return;
       
       inorder(head->left);
       nodes.push_back(head);
       inorder(head->right);
       
   }    
    
    
    Node * bToDLL(Node *root)  {
        nodes.clear();
        inorder(root);
        
        int n = nodes.size();
        
        if(n == 0) return root;
        else {
    
            for(int i = 1; i < n; i++) {
                nodes[i]->left = nodes[i-1];
                nodes[i-1]->right = nodes[i];
            }
            
            nodes[0]->left = NULL; // corner case 1
            nodes[n-1]->right = NULL; // corner case 2
           

            Node *ans = nodes[0];  // pointing to the 1st inorder list node
            return ans;
        }
    
    }