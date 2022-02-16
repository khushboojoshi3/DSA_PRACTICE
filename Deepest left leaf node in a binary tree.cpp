// Deepest left leaf node in a binary tree
// https://www.geeksforgeeks.org/deepest-left-leaf-node-in-a-binary-tree/
// Given a Binary Tree, find the deepest leaf node that is left child of its parent. For example, consider the following tree. 
// The deepest left leaf node is the node with value 9. 
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


void printInorder(Node* root){
    if(!root) return;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}
void deepestLeftLeafHelper(Node* root,int level,int &maxLevel,bool isLeft,Node* &result){
    if(!root) return;
    //isLeft represents if it is the left child of its parent
    if(isLeft==true && root->left==NULL && root->right==NULL && level>maxLevel){
        maxLevel=level;
        result=root;
        return;
    }
    deepestLeftLeafHelper(root->left,level+1,maxLevel,true,result);
    deepestLeftLeafHelper(root->right,level+1,maxLevel,false,result);
}
Node* deepestLeftLeaf(Node* root){
    int maxLevel=0;
    Node* result=NULL;
    int level=0;
    deepestLeftLeafHelper(root,level,maxLevel,false,result);
    return result;
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->right = new Node(7);
    root->right->right->right = new Node(8);
    root->right->left->right->left = new Node(9);
    root->right->right->right->right = new Node(10);
 
    Node *result = deepestLeftLeaf(root);
    if (result)
        cout << "The deepest left child is " << result->data;
    else
        cout << "There is no left leaf in the given tree";
 
    return 0;
}
