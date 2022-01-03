#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution {
    void dfs(Node*curr,Node*node,vector<Node*>&vis)
    {
        vis[node->val]=node;
        for(auto ele:curr->neighbors)
        {
            if(vis[ele->val]==NULL)
            {
                Node*newnode=new Node(ele->val);
                (node->neighbors).push_back(newnode);
                dfs(ele,newnode,vis);
            }
            else{
                (node->neighbors).push_back(vis[ele->val]);
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
        {
            return NULL;
        }

        vector<Node*>vis(1000,NULL);
        Node* copy=new Node(node->val);
        vis[node->val]=copy;
        for(auto curr : node->neighbors)
        {
            if(vis[curr->val]==NULL)
            {
                Node* newnode=new Node(curr->val);
                (copy->neighbors).push_back(newnode);
                dfs(curr,newnode,vis);
            }
            else{
                (copy->neighbors).push_back(vis[curr->val]);
            }
        }
        return copy;
    }
};