// Count triplets in a sorted doubly linked list whose sum is equal to a given value x
// https://www.geeksforgeeks.org/count-triplets-sorted-doubly-linked-list-whose-sum-equal-given-value-x/
// Given a sorted doubly linked list of distinct nodes(no two nodes have the same data) and a value x. Count triplets in the list that sum up to a given value x.
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
int countPairs(Node* curr,Node* start,Node* end,int target){
    int cnt=0;
    // The loop terminates when either of two pointers
    // become NULL, or they cross each other (end->next
    // == start), or they become same (start == end)
    while(start && end && start!=end && end->next!=start){
        int sum=start->data + end->data;
        if(sum==target){
            // cout<<curr->data<<" "<<start->data<<" "<<end->data<<"\n";
            cnt++;
            start=start->next;
            end=end->prev;
        }
        else if(sum<target){
            start=start->next;
        }
        else{
            end=end->prev;
        }
    }
    return cnt;
}
int countTriplets(Node* head,int target){
    if(head==NULL) return 0;
    Node* curr,*first,*last;
    int count=0;
    last=head;
    while(last->next){
        last=last->next;
    }
    curr=head;
    while(curr!=NULL){
        first=curr->next;
        count+=countPairs(curr,first,last,target-curr->data);
        curr=curr->next;
    }
    return count;
}

int main() {
    Node* head=NULL;
    insertAtBeginning(head, 9);
    insertAtBeginning(head, 8);
    insertAtBeginning(head, 6);
    insertAtBeginning(head, 5);
    insertAtBeginning(head, 4);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 1);
    int target=17;
    cout << "Count = "<< countTriplets(head, target);
    return 0;
}
