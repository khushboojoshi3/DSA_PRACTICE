// https://www.geeksforgeeks.org/stack-permutations-check-if-an-array-is-stack-permutation-of-other/
// https://leetcode.com/problems/validate-stack-sequences/
// Stack Permutations (Check if an array is stack permutation of other)
// A stack permutation is a permutation of objects in the given input queue
// which is done by transferring elements from input queue to the output queue
// with the help of a stack and the built-in push and pop functions.

#include<bits/stdc++.h>
using namespace std;
 
// function to check if input queue is
// permutable to output queue
bool checkStackPermutation(int ip[], int op[], int n)
{
    stack<int> st;
    int j=0;
    for(int i=0;i<n;i++){
        int x=ip[i];
        st.push(x);
        while(!st.empty() && st.top()==op[j]){
            st.pop();
            j++;
        }
    }
    return st.empty();
}

int main(){
    // int input[] = {1, 2, 3,4,5};
 
    // // Output Queue
    // int output[] = {4,3,5,1, 2};

    int input[] = {1, 2, 3};
 
    // Output Queue
    int output[] = {2,1,3};
 
    int n = 3;
 
    if (checkStackPermutation(input, output, n))
        cout << "Yes";
    else
        cout << "Not Possible";
    return 0;
}
