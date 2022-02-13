// https://www.geeksforgeeks.org/find-a-triplet-from-three-linked-lists-with-sum-equal-to-a-given-number/
// Find a triplet from three linked lists with sum equal to a given number
// Given three linked lists, say a, b and c, find one node from each list such that the sum of the values of the nodes is equal to a given number. 
// For example, if the three linked lists are 12->6->29, 23->5->8, and 90->20->59, and the given number is 101, the output should be triple “6 5 90”.
// Algorithm-
// a. Sort List1 in ascending order.(Not neccessary)
// b. Sort List2 in ascending order.
// c. Sort List3 in descending order.
// d. Traverse in the linked lists, pick first element in List1 and for every element in List1 pick a pair of elements in List2 and List3.
// e. If sum of the elements is equal to given number print them.
// f. If sum is less than given number move position in List2.
// g. If sum is greater than given number move position in List3.
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
Node* midPoint(Node* head){
    if(!head || !head->next) return head;
    Node* slow=head;
    Node* fast=head->next;
    while(fast && fast->next){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
Node* merge(Node* a,Node* b,bool inc){
    if(inc==true){
        if(!a) return b;
        else if(!b) return a;
        Node* c;
        if(a->data<b->data){
            c=a;
            c->next=merge(a->next,b,inc);
        }
        else{
            c=b;
            c->next=merge(a,b->next,inc);
        }
        return c;
    }
    else{
        if(!a) return b;
        else if(!b) return a;
        Node* c;
        if(a->data>b->data){
            c=a;
            c->next=merge(a->next,b,inc);
        }
        else{
            c=b;
            c->next=merge(a,b->next,inc);
        }
        return c;
    }
}


Node* mergeSort(Node* head,bool inc){
    if(!head || !head->next) return head;
    Node* mid=midPoint(head);
    Node* a=head;
    Node* b=mid->next;
    mid->next=NULL;
    a=mergeSort(a,inc);
    b=mergeSort(b,inc);
    Node* c=merge(a,b,inc);
    return c;
}

void findAllTriplets(Node* list1,Node* list2,Node* list3,int target){
    Node* a=list1;
    bool found=false;
    while(a){
        Node* b=list2;
        Node* c=list3;
        while(b && c){
            int sum=a->data + b->data + c->data;
            if(sum==target){
                found=true;
                cout<<a->data<<" "<<b->data<<" "<<c->data<<"\n";
                b=b->next;
                c=c->next;
            }
            else if(sum<target){
                b=b->next;
            }
            else{
                c=c->next;
            }
        }
        a=a->next;
    }
    if(found==false){
        cout<<"No such triplet\n";
    }
}

int main() {
    Node* list1=NULL;
    Node* list2=NULL;
    Node* list3=NULL;
    /*create a linked list 'a' 10->15->5->20 */
    insertAtBeginning(list1, 20);
    insertAtBeginning(list1, 4);
    insertAtBeginning(list1, 15);
    insertAtBeginning(list1, 10);
 
    /*create a sorted linked list 'b' 2->4->9->10 */
    insertAtBeginning(list2, 10);
    insertAtBeginning(list2, 9);
    insertAtBeginning(list2, 4);
    insertAtBeginning(list2, 2);
 
    /*create another sorted
    linked list 'c' 8->4->2->1 */
    insertAtBeginning(list3, 1);
    insertAtBeginning(list3, 2);
    insertAtBeginning(list3, 4);
    insertAtBeginning(list3, 8);

//     while(list1){
//         cout<<list1->data<<" ";
//         list1=list1->next;
//     }
//    cout<<"\n";
    
//     while(list2){
//         cout<<list2->data<<" ";
//         list2=list2->next;
//     }
//    cout<<"\n";

    
//     while(list3){
//         cout<<list3->data<<" ";
//         list3=list3->next;
//     }
//    cout<<"\n";
    mergeSort(list1,true);
    mergeSort(list2,true);
    mergeSort(list3,false);
    int target=25;
    findAllTriplets(list1,list2,list3,target);
    return 0;
}
