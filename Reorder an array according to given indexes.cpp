// Reorder an array according to given indexes
// Difficulty Level : Medium
// Last Updated : 13 Jan, 2022
// Given two integer arrays of same size, “arr[]” and “index[]”, reorder elements in “arr[]” according to given index array. It is not allowed to given array arr’s length.

// Example: 

// Input:  arr[]   = [10, 11, 12];
//         index[] = [1, 0, 2];
// Output: arr[]   = [11, 10, 12]
//         index[] = [0,  1,  2] 

// Input:  arr[]   = [50, 40, 70, 60, 90]
//         index[] = [3,  0,  4,  1,  2]
// Output: arr[]   = [40, 60, 90, 50, 70]
//         index[] = [0,  1,  2,  3,   4]
// Expected time complexity O(n) and auxiliary space O(1)

#include <bits/stdc++.h>
using namespace std;
void reorder(int arr[], int index[], int n)
{
    for(int i=0;i<n;i++){
        while(index[i]!=i){
            swap(arr[i],arr[index[i]]);
            swap(index[index[i]],index[i]);
        }
    }
}
int main() {
    int arr[] = {50, 40, 70, 60, 90};
    int index[] = {3,  0,  4,  1,  2};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    reorder(arr, index, n);
 
    cout << "Reordered array is: \n";
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
 
    cout << "\nModified Index array is: \n";
    for (int i=0; i<n; i++)
        cout << index[i] << " ";
    return 0;
}
