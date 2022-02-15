// Create a Doubly Linked List from a Ternary Tree
// https://www.geeksforgeeks.org/create-doubly-linked-list-ternary-ree/
// Given a ternary tree, create a doubly linked list out of it.
// A ternary tree is just like binary tree but instead of having two nodes, it has three nodes i.e. left, middle, right.
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node* middle;
    Node(int v){
        data=v;
        left=NULL;
        right=NULL;
        middle=NULL;
    }
};
Node* tail;
void push(Node* node){
    if(tail==NULL){
        tail=node;
        node->left=NULL;
        node->right=NULL;
        node->middle=NULL;
        return ;
    }
    tail->right=node;
    node->left=tail;
    node->right=NULL;
    node->middle=NULL;
    tail=node;
}
void TernaryTreeToList(Node* root,Node* &head){
    if(!root) return;
    if(head==NULL){
        head=root;
    }
    Node* left=root->left;
    Node* right=root->right;
    Node* middle=root->middle;
    push(root);
    TernaryTreeToList(left,head);
    TernaryTreeToList(middle,head);
    TernaryTreeToList(right,head);
}

void printList(Node* head){
    cout<<"Created Double Linked list is:\n";
    while(head){
        cout<<head->data<<" ";
        head=head->right;
    }
}
int main()
{
    // Constructing ternary tree as shown in above figure
    Node* root = new Node(30);
 
    root->left = new Node(5);
    root->middle = new Node(11);
    root->right = new Node(63);
 
    root->left->left = new Node(1);
    root->left->middle = new Node(4);
    root->left->right = new Node(8);
 
    root->middle->left = new Node(6);
    root->middle->middle = new Node(7);
    root->middle->right = new Node(15);
 
    root->right->left = new Node(31);
    root->right->middle = new Node(55);
    root->right->right = new Node(65);
 
    Node* head = NULL;
    tail=NULL;
    TernaryTreeToList(root, head);
 
    printList(head);
 
    return 0;
}

