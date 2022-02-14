// Perfect Binary Tree Specific Level Order Traversal
// https://www.geeksforgeeks.org/perfect-binary-tree-specific-level-order-traversal/
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
void printSpecificLevelOrder(Node* root){
    if(!root) return ;
    cout<<root->data;

    if(root->left){
        cout<<" "<<root->left->data<<" "<<root->right->data;
    }

    if(root->left->left==NULL){
        return ;
    }

    queue<Node*> q;
    q.push(root->left);
    q.push(root->right);

    Node* first=NULL;
    Node* second=NULL;
    while(!q.empty()){
        first=q.front();
        q.pop();
        second=q.front();
        q.pop();
        cout<<" "<<first->left->data<<" "<<second->right->data<<" "<<first->right->data<<" "<<second->left->data;

        if(first->left->left!=NULL){
            q.push(first->left);
            q.push(second->right);
            q.push(first->right);
            q.push(second->left);
        }
    }
}
int main()
{
    //Perfect Binary Tree of Height 4
    Node *root = new Node(1);
 
    root->left        = new Node(2);
    root->right       = new Node(3);
 
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
    root->right->left  = new Node(6);
    root->right->right = new Node(7);
 
    root->left->left->left  = new Node(8);
    root->left->left->right  = new Node(9);
    root->left->right->left  = new Node(10);
    root->left->right->right  = new Node(11);
    root->right->left->left  = new Node(12);
    root->right->left->right  = new Node(13);
    root->right->right->left  = new Node(14);
    root->right->right->right  = new Node(15);
 
    root->left->left->left->left  = new Node(16);
    root->left->left->left->right  = new Node(17);
    root->left->left->right->left  = new Node(18);
    root->left->left->right->right  = new Node(19);
    root->left->right->left->left  = new Node(20);
    root->left->right->left->right  = new Node(21);
    root->left->right->right->left  = new Node(22);
    root->left->right->right->right  = new Node(23);
    root->right->left->left->left  = new Node(24);
    root->right->left->left->right  = new Node(25);
    root->right->left->right->left  = new Node(26);
    root->right->left->right->right  = new Node(27);
    root->right->right->left->left  = new Node(28);
    root->right->right->left->right  = new Node(29);
    root->right->right->right->left  = new Node(30);
    root->right->right->right->right  = new Node(31);
 
    cout << "Specific Level Order traversal of binary tree is \n";
    printSpecificLevelOrder(root);
 
    return 0;
}
