#include<bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};
map<string,int>m;
string solve(Node*root){
    string s="";
    if(root==NULL)
    {
        return "$";// To differentiate between lef and right sub treen nodes
    }
    //check leaf node
    if(root->right==NULL and root->left==NULL)
    {
        s+=root->data;
        return s;
    }
    s+=root->data;
    s+=solve(root->left);
    s+=solve(root->right);
    m[s]++;
    return s;
}
int dupSub(Node *root)
{
    solve(root);
    for(auto x :m)
    {
        if(x.second>=2)
        {
            return 1;
        }
    }
    return 0;

}