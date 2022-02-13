// C++ program for diagonal
// traversal of Binary Tree
#include <bits/stdc++.h>
using namespace std;
 
// Tree node

struct Node
{
    int data;
    Node *left, *right;
};
 
/* root - root of the binary tree
   d -  distance of current line from rightmost
        -topmost slope.
   diagonalPrint - multimap to store Diagonal
                   elements (Passed by Reference) */

                   ////////////////////////////Method 1 timecomplexity O(NlogN)//////////////
// void diagonalPrintUtil(Node* root, int d,
//                 map<int, vector<int>> &diagonalPrint)
// {
//    if(root==NULL)
//    {
//        return ;
//    }

//    diagonalPrint[d].push_back(root->data);
//    diagonalPrintUtil(root->left,d+1,diagonalPrint);
//    diagonalPrintUtil(root->right,d,diagonalPrint);

// }
 
// // Print diagonal traversal
// // of given binary tree
// void diagonalPrint(Node* root)
// {
     
//   map<int, vector<int>> diagonalPrint;
//   diagonalPrintUtil(root,0,diagonalPrint);
//   for (auto it : diagonalPrint)
//   {
//       for (auto  x: it.second)
//       {
//           cout<<x<<" ";
//       }
//       cout<<endl;
      
//   }
  

// }
 
// Utility method to create a new node
Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
 
 //////////////////////////Method 2 TIme complexity O(N) /////////////////////////
 vector <vector <int>> result;
void diagonalPrint(Node* root)
{
    if(root==NULL)
    {
        return ;
    }
    queue<Node*>q;
    q.push(root);
    while (!q.empty())
    {
        int n=q.size();
        vector<int>arr;
        for (int i = 0; i < n; i++)
        {
            Node*temp=q.front();
            q.pop();
            while (temp)
            {
                arr.push_back(temp->data);
                if(temp->left)
                {
                    q.push(temp->left);

                }

                temp=temp->right;
            }
            
        }
        result.push_back(arr);
        
    }
     for(int i=0 ; i<result.size() ; i++)
    {
        for(int j=0 ; j<result[i].size() ; j++)
            cout<<result[i][j]<<"  ";
        cout<<endl;
    }
}
// Driver program
int main()
{
    Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
 
    /*  Node* root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        root->left->left = newNode(9);
        root->left->right = newNode(6);
        root->right->left = newNode(4);
        root->right->right = newNode(5);
        root->right->left->right = newNode(7);
        root->right->left->left = newNode(12);
        root->left->right->left = newNode(11);
        root->left->left->right = newNode(10);*/
 
    diagonalPrint(root);
 
    return 0;
}