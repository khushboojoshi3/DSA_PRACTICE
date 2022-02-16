// Double Tree
// https://www.geeksforgeeks.org/double-tree/
// Write a program that converts a given tree to its Double tree.
// To create Double tree of the given tree, create a new duplicate for each node, and insert the duplicate as the left child of the original node. 
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

Node* doubleTree(Node* root){
    if(!root) return NULL;
    Node* newNode=new Node(root->data);
    Node* l=doubleTree(root->left);
    Node* r=doubleTree(root->right);
    root->left=newNode;
    root->right=r;
    newNode->left=l;
    return root;
}
void printInorder(Node* root){
    if(!root) return;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}
int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
     
    cout << "Inorder traversal of the original tree is \n";
    printInorder(root);
     
    doubleTree(root);
         
    cout << "\nInorder traversal of the double tree is \n";
    printInorder(root);
     
    return 0;
}
