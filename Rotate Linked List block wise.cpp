// Rotate Linked List block wise
// https://www.geeksforgeeks.org/rotate-linked-list-block-wise/
// Given a Linked List of length n and block length k rotate in a circular manner towards right/left each block by a number d. 
// If d is positive rotate towards right else rotate towards left.

// Examples: 

// Input: 1->2->3->4->5->6->7->8->9->NULL, 
//         k = 3 
//         d = 1
// Output: 3->1->2->6->4->5->9->7->8->NULL
// Explanation: Here blocks of size 3 are
// rotated towards right(as d is positive) 
// by 1.
 
// Input: 1->2->3->4->5->6->7->8->9->10->
//                11->12->13->14->15->NULL, 
//         k = 4 
//         d = -1
// Output: 2->3->4->1->6->7->8->5->10->11
//              ->12->9->14->15->13->NULL
// Explanation: Here, at the end of linked 
// list, remaining nodes are less than k, i.e.
// only three nodes are left while k is 4. 
// Rotate those 3 nodes also by d.
//Code for helper Function is taken from here
//https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1/#
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int v){
        data=v;
        next=NULL;
    }
};

void insertAtBeginning(Node* &head,int val){
    Node* newNode=new Node(val);
    newNode->next=head;
    head=newNode;
}

Node* helper(Node* blockHead,Node* blockTail,int d,Node* &tail,int k){
    if(d==0){
        return blockHead;
    }
    if(d>0){
        d=k-d;
    }
    else{
        d=abs(d);
    }
    Node* curr;
    blockTail->next=blockHead;
    curr=blockHead;
    for(int i=0;i<d-1;i++){
        curr=curr->next;
    }
    tail=curr;
    blockHead=curr->next;
    return blockHead;
}
Node* rotateByBlocks(Node* head,int k,int d){
    if(!head || !head->next){
        return head;
    }
    if(d==0) return head;
    Node* tail=NULL;
    Node* temp=head;
    int i;
    for(i=1;temp->next && i<k;i++){
        temp=temp->next;
    }
    Node* nextBlock=temp->next;
    if(i<k){
        head=helper(head,temp,d%k,tail,i); //i is the length of block
    }
    else{
        head=helper(head,temp,d%k,tail,k);
    }
    tail->next=rotateByBlocks(nextBlock,k,d%k);
    return head;
}

void printList(Node* node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
int main() {
    Node* head=NULL;
    for (int i = 15; i > 0; i -= 1){
        insertAtBeginning(head, i);
    }
    
    int k=4,d=-1;
    head = rotateByBlocks(head, k, d);
    printList(head);
    return 0;
}
