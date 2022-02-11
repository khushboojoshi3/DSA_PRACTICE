// https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/
// Sum of minimum and maximum elements of all subarrays of size k.
// Given an array of both positive and negative integers, 
// the task is to compute sum of minimum and maximum elements of all sub-array of size k.
// Input : arr[] = {2, 5, -1, 7, -3, -1, -2}  
//         K = 4
// Output : 18
// Explanation : Subarrays of size 4 are : 
//      {2, 5, -1, 7},   min + max = -1 + 7 = 6
//      {5, -1, 7, -3},  min + max = -3 + 7 = 4      
//      {-1, 7, -3, -1}, min + max = -3 + 7 = 4
//      {7, -3, -1, -2}, min + max = -3 + 7 = 4   
//      Sum of all min & max = 6 + 4 + 4 + 4 
//                           = 18      
#include<bits/stdc++.h>
using namespace std;
 
// Returns sum of min and max element of all subarrays
// of size k
int SumOfKsubArray(int arr[] , int n , int k)
{
    deque<int> mini(k);
    deque<int> maxi(k);
    int i;
    for(i=0;i<k;i++){
        while((!mini.empty()) && arr[mini.back()]>=arr[i]){
            mini.pop_back();
        }

        while((!maxi.empty()) && arr[maxi.back()]<=arr[i]){
            maxi.pop_back();
        }
        mini.push_back(i);
        maxi.push_back(i);
    }

    //mini front will contain the index of minimum element in subarray of size k
    //maxi front will contain the index of maximum element in subarray of size k
    int sum=0;
    for(;i<n;i++){
        sum+=arr[mini.front()]+arr[maxi.front()];
        while( !mini.empty() && mini.front()<=i-k){
            mini.pop_front();
        }
        while(!maxi.empty() && maxi.front()<=i-k){
            maxi.pop_front();
        }
        while((!mini.empty()) && arr[mini.back()]>=arr[i]){
            mini.pop_back();
        }

        while((!maxi.empty()) && arr[maxi.back()]<=arr[i]){
            maxi.pop_back();
        }
        mini.push_back(i);
        maxi.push_back(i);
    }
    sum+=arr[mini.front()]+arr[maxi.front()];
    return sum;
}

int main()
{
    int arr[] = {2, 5, -1, 7, -3, -1, -2} ;
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    cout << SumOfKsubArray(arr, n, k) ;
    return 0;
}
