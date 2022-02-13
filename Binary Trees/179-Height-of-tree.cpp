#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        left=NULL;
        right=NULL;
        data=x;
    }
};
int height(struct Node* node)
{
   if(node==NULL)
   {
       return 0;
   }
   int right=1+height(node->right);
   int left=1+height(node->left);
   return max(right,left);

}
int main()
{
    Node*root=new Node(1);
    root->right=new Node(3);
    root->right->right=new Node(5);
   root->right->right->right=new Node(2);
    cout<<height(root);
    return 0;
}