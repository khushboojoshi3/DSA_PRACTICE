// Change a Binary Tree so that every node stores sum of all nodes in left subtree
// https://www.geeksforgeeks.org/change-a-binary-tree-so-that-every-node-stores-sum-of-all-nodes-in-left-subtree/
// Given a Binary Tree, change the value in each node to sum of all the values in the nodes in the left subtree including its own.
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int v){
        data=v;
        left=NULL;
        right=NULL;
    }
};


int updatetree(Node* root){
    if(!root) return 0;
    int l=updatetree(root->left);
    int r=updatetree(root->right);
    int temp=root->data;
    root->data=root->data+l;
    return temp+l+r;
}
void inorder(Node* node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}
int main()
{
    // Constructing ternary tree as shown in above figure
    Node *root = new Node(1);
    root->left     = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    updatetree(root);
 
    cout << "Inorder traversal of the modified tree is: \n";
    inorder(root);
    return 0;
}

