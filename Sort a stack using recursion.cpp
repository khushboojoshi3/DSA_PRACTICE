// Sort a stack using recursion
// https://www.geeksforgeeks.org/sort-a-stack-using-recursion/

#include<bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &st,int key){
    if(st.empty() || key>st.top()){
        st.push(key);
        return ;
    }
    int top=st.top();
    st.pop();
    sortedInsert(st,key);
    st.push(top);
}

void sortStack(stack<int> &st){
    if(st.empty()){
        return ;
    }
    int top=st.top();
    st.pop();
    sortStack(st);
    sortedInsert(st,top);
}
void printStack(stack<int> stack)
{
    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}
 
int main()
{
    vector<int> arr = { 5, -2, 9, -7, 3 };
 
    stack<int> st;
    for (int i: arr) {
        st.push(i);
    }
 
    cout << "Stack before sorting: ";
    printStack(st);
 
    sortStack(st);
 
    cout << "Stack after sorting: ";
    printStack(st);
 
    return 0;
}
