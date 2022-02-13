#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
 bool check(Node *root)
    {
       if(!root) return true;
       bool foundLeaf = false;
       queue<Node*> q;
       q.push(root);
       q.push(NULL);
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            if(temp){
                if(temp->left==NULL&&temp->right==NULL) foundLeaf = true;
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            if(temp==NULL){
                if(foundLeaf&&!q.empty()) return false;
                if(!q.empty()) q.push(NULL);
            }
        } return true;
    }