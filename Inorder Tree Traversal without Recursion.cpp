// Inorder Tree Traversal without Recursion
// https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
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
void inOrder(Node* root){
    stack<Node*> st;
    Node* curr=root;
    while(curr!=NULL || !st.empty()){
        while(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        st.pop();
        cout<<curr->data<<" ";
        curr=curr->right;
    }
}
int main()
{
 
    /* Constructed binary tree is
              1
            /   \
          2      3
        /  \
      4     5
    */
    Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
 
    inOrder(root);
    return 0;
}
