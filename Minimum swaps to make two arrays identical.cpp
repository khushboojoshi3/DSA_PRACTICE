// https://www.geeksforgeeks.org/minimum-swaps-to-make-two-array-identical/
// Minimum swaps to make two arrays identical

// Given two arrays that have the same values but in a different order, we need to make a second array the same as a first array using the minimum number of swaps. 
// Examples:  

// Input  : arrA[] = {3, 6, 4, 8}, 
//          arrB[] = {4, 6, 8, 3}
// Output : 2
// we can make arrB to same as arrA in 2 swaps 
// which are shown below,
// swap 4 with 8,   arrB = {8, 6, 4, 3}
// swap 8 with 3,   arrB = {3, 6, 4, 8}


// This problem can be solved by modifying the array B. We save the index of array A elements in array B 
//i.e. if ith element of array A is at jth position in array B, then we will make arrB[i] = j 
// For above given example, modified array B will be, arrB = {3, 1, 0, 2}. 
//This modified array represents the distribution of array A element in array B and our goal is to sort this modified array
// in a minimum number of swaps because after sorting only array B element will be aligned with array A elements. 
//problem boils down to minimum swaps to sort an array
#include<bits/stdc++.h>
using namespace std;
int minSwapsToSort(int arr[], int n)
{
    vector<pair<int,int>> vec;
    for(int i=0;i<n;i++){
        vec.push_back({arr[i],i});
    }
    sort(vec.begin(),vec.end());
    int ans=0;
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){
        if(visited[i]==true || i==vec[i].second){
            continue;
        }
        int clen=0;
        int j=i;
        while(visited[j]==false){
            visited[j]=true;
            clen++;
            j=vec[j].second;
        }
        ans+=clen-1;
    }
    return ans;
}
int minSwapToMakeArraySame(int a[], int b[], int n)
{
    unordered_map<int,int> umap;
    for(int i=0;i<n;i++){
        umap[b[i]]=i;
    }

    for(int i=0;i<n;i++){
        b[i]=umap[a[i]];
    }

    return minSwapsToSort(b, n);
}
int main() {
    int a[] = {3, 6, 4, 8};
    int b[] = {4, 6, 8, 3};
 
    int n = sizeof(a) / sizeof(int);
    cout << minSwapToMakeArraySame(a, b, n);
    return 0;
}
