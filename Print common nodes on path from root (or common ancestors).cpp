// Print common nodes on path from root (or common ancestors)
// https://www.geeksforgeeks.org/print-common-nodes-path-root-common-ancestors/
// Given a binary tree and two nodes, the task is to Print all the nodes that are common for 2 given nodes in a binary tree.
// Given binary tree is :
//                      1
//                   /    \
//                 2       3
//               /   \     /  \
//              4     5   6    7
//             /        /  \
//            8        9   10

// Given nodes 9 and 7, so the common nodes are:-
// 1, 3
// Asked in : Amazon
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

Node* LCA(Node* root,int a,int b){
    if(!root) return NULL;
    if(root->data==a || root->data==b){
        return root;
    }
    Node* left=LCA(root->left,a,b);
    Node* right=LCA(root->right,a,b);
    if(left && right){
        return root;
    }
    if(!left){
        return right;
    }
    return left;
}
bool printAncestors(Node* root,int target){
    if(!root) return false;
    if(root->data==target){
        cout<<root->data<<" ";
        return true;
    }
    if(printAncestors(root->left,target) || printAncestors(root->right,target)){
        cout<<root->data<<" ";
        return true;
    }
    return false;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->right->left->left = new Node(9);
    root->right->left->right = new Node(10);
    Node* lca=LCA(root, 9, 10);
    if(lca==NULL){
        cout << "No Common nodes";
    }  
    printAncestors(root,lca->data);
    return 0;
}

