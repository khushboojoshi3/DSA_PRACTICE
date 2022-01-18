// Given two sorted arrays A and B, generate all possible arrays such that first element is taken from A then from B then from A and so on in increasing order till the arrays exhausted. The generated arrays should end with an element from B.
// For Example 
 

 
// A = {10, 15, 25}
// B = {1, 5, 20, 30}

// The resulting arrays are:
//   10 20
//   10 20 25 30
//   10 30
//   15 20
//   15 20 25 30
//   15 30
//   25 30

#include <iostream>
using namespace std;
void printArr(int arr[], int n)
{
    for (int i = 0; i <n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void helper(int A[],int B[],int C[],int i,int j,int m,int n,int len,bool flag){
    if(flag){
        if(len>0){
            printArr(C,len);
        }
        for(int k=i;k<m;k++){
            if(len==0){
                C[len]=A[k];
                helper(A,B,C,k+1,j,m,n,len+1,!flag);
            }
            else{
                if(A[k]>C[len-1]){
                    C[len]=A[k];
                    helper(A,B,C,k+1,j,m,n,len+1,!flag);
                }
            }
        }
    }

    else{
        for(int l=j;l<n;l++){
            if(B[l]>C[len-1]){
                C[len]=B[l];
                helper(A,B,C,i,l+1,m,n,len+1,!flag);
            }
        }
    }
}
int main() {
    int A[] = {10, 15, 25};
    int B[] = {5, 20, 30};
    int m = sizeof(A)/sizeof(A[0]);
    int n = sizeof(B)/sizeof(B[0]);
    int C[m+n];
    helper(A, B, C,0,0,m,n,0,true);
    return 0;
}
