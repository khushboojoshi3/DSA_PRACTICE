// Lexicographically smallest array after at-most K consecutive swaps
// https://www.geeksforgeeks.org/lexicographically-smallest-array-k-consecutive-swaps/
// Given an array arr[], find the lexicographically smallest array that can be obtained after performing at maximum of k consecutive swaps. 
// Examples : 
 

// Input: arr[] = {7, 6, 9, 2, 1}
//         k = 3
// Output: arr[] = {2, 7, 6, 9, 1}
// Explanation: Array is: 7, 6, 9, 2, 1
// Swap 1:   7, 6, 2, 9, 1
// Swap 2:   7, 2, 6, 9, 1
// Swap 3:   2, 7, 6, 9, 1
// So Our final array after k = 3 swaps : 
// 2, 7, 6, 9, 1

// Input: arr[] = {7, 6, 9, 2, 1}
//         k = 1
// Output: arr[] = {6, 7, 9, 2, 1}

#include<bits/stdc++.h>
using namespace std ;
void minimizeWithKSwaps(int arr[], int n, int k)
{
    for(int i=0;i<n-1 && k>0;i++){
        // Set the position where we want
        // to put the smallest integer
        int pos=i;
        for(int j=i+1;j<n;j++){
            // If we exceed the Max swaps
            // then terminate the loop
            if(j-i>k){
                break;
            }
            // Find the minimum value from i+1 to
            // max k or n
            if(arr[j]<arr[pos]){
                pos=j;
            }
        }

        // Swap the elements from Minimum position
        // we found till now to the i index
        for(int j=pos;j>i;j--){
            swap(arr[j],arr[j-1]);
        }

        // Set the final value after swapping pos-i
        // elements
        k=k-(pos-i);
    }
}
int main()
{
    // int arr[] = {7, 6, 9, 2, 1};
    int arr[] = {7, 2,6,9, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
 
    minimizeWithKSwaps(arr, n, k);
 
    //Print the final Array
    for (int i=0; i<n; ++i)
        cout << arr[i] <<" ";
}
