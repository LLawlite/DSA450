#include <bits/stdc++.h>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// Recursive function to perform inorder traversal on the tree
void inorder(Node *root)
{
    // return if the current node is empty
    if (root == nullptr)
    {
        return;
    }

    // Traverse the left subtree
    inorder(root->left);

    // Display the data part of the root (or current node)

    // Traverse the right subtree
    inorder(root->right);
    cout << root->data << " ";
}

////////////Wihtout iteration //////////////////////////

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> inorderTraversal(TreeNode *root)
{

    stack<TreeNode *> s;
    vector<int> ans;
    TreeNode *curr = root;
    while (!s.empty() || curr != NULL)
    {

        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
            if(curr->val=NULL)
            {

            ans.push_back(curr->val);
            }

        curr = s.top();

        s.pop();

        curr = curr->right;
    }
    return ans;
}
int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    inorder(root);

    return 0;
}
