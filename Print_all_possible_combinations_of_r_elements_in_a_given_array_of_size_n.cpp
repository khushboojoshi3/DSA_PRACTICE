// Print all possible combinations of r elements in a given array of size n
// Difficulty Level : Hard
// Last Updated : 14 Jan, 2022
 
// Given an array of size n, generate and print all possible combinations of r elements in array. For example, if input array is {1, 2, 3, 4} and r is 2, 
// then output should be {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4} and {3, 4}.
// Following are two methods to do this. 
// Method 1 (Fix Elements and Recur) 
// We create a temporary array ‘data[]’ which stores all outputs one by one. The idea is to start from first index (index = 0) in data[],
// one by one fix elements at this index and recur for remaining indexes. 
// Let the input array be {1, 2, 3, 4, 5} and r be 3. We first fix 1 at index 0 in data[], then recur for remaining indexes, then we fix 2 at index 0 and recur.
// Finally, we fix 3 and recur for remaining indexes. When number of elements in data[] becomes equal to r (size of a combination), we print data[].

#include<bits/stdc++.h>
using namespace std;
void combinationUtil(int arr[], int n, int r,
                    int index, int data[], int i)
{
    if(index==r){
        for(int j=0;j<r;j++){
            cout<<data[j]<<" ";
        }
        cout<<"\n";
        return ;
    }
    if(i>=n){
        return;
    }

    
    data[index]=arr[i];
    combinationUtil(arr,n,r,index+1,data,i+1);

    while (arr[i] == arr[i+1])
        i++;
    
    combinationUtil(arr,n,r,index,data,i+1);
}
void printCombination(int arr[], int n, int r)
{
    // A temporary array to store
    // all combination one by one
    sort(arr,arr+n);
    int data[r];
 
    // Print all combination using
    // temporary array 'data[]'
    combinationUtil(arr, n, r, 0, data, 0);
}
int main() {
    int arr[] = {1, 2, 1, 3, 1};
    int r = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    printCombination(arr, n, r);
    return 0;
}
