// Sort the biotonic doubly linked list
// https://www.geeksforgeeks.org/sort-biotonic-doubly-linked-list/
// Sort the given biotonic doubly linked list.
//  A biotonic doubly linked list is a doubly linked list which is first increasing and then decreasing.
//  A strictly increasing or a strictly decreasing list is also a biotonic doubly linked list.
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int v){
        data=v;
        next=NULL;
        prev=NULL;
    }
};

void insertAtBeginning(Node* &head,int val){
    Node* newNode=new Node(val);
    if(head==NULL){
        head=newNode;
    }
    else{
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
}

void reverse(Node* &head){
    Node* temp=NULL;
    Node* curr=head;
    while(curr){
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        curr=curr->prev;
    }
    // Before changing head, check for the cases
    // like empty list and list with only one node
    if(temp){
        head=temp->prev;
    }
}

Node* merge(Node* a,Node* b){
    if(!a) return b;
    if(!b) return a;
    Node* c;
    if(a->data<=b->data){
        c=a;
        Node* temp=merge(a->next,b);
        c->next=temp;
        temp->prev=c;
    }
    else{
        c=b;
        Node* temp=merge(a,b->next);
        c->next=temp;
        temp->prev=c;
    }
    return c;
}

Node* sort(Node* head){
    if(!head || !head->next) return head;
    Node* curr=head->next;
    while(curr){
        if(curr->data < curr->prev->data){
            break;
        }
        curr=curr->next;
    }
    if(curr==NULL){ //list is already sorted
        return head;
    }
    curr->prev->next=NULL;
    curr->prev=NULL;
    reverse(curr);
    return merge(head,curr);
}
void printList(Node* head)
{
    // if list is empty
    if (head == NULL)
        cout << "Doubly Linked list empty";
 
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
int main() {
    Node* head=NULL;
    insertAtBeginning(head, 1);
    insertAtBeginning(head, 4);
    insertAtBeginning(head, 6);
    insertAtBeginning(head, 10);
    insertAtBeginning(head, 12);
    insertAtBeginning(head, 7);
    insertAtBeginning(head, 5);
    insertAtBeginning(head, 2);
    cout << "Original Doubly linked list:n";
    printList(head);
 
    // sort the biotonic DLL
    head = sort(head);
 
    cout << "\nDoubly linked list after sorting:n";
    printList(head);
    return 0;
}
