// You are given an array A with elements 0 to n-1, numbers can be repeated in the array. Create  sets where

// S[i]={a[i],a[a[i]],a[a[a[i]]]…}. Set has all elements unique. Find the size of the largest set.
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n=17;
    int arr[]={5,6,3,1,4,7,8,9,2,11,12,2,4,6,9,4,1};
    unordered_map<int,int> umap;
    int i;
    for(int j=0;j<n;j++){
        i=j;
        while(umap.find(arr[i])==umap.end()){
            umap[arr[i]]=1;
            i=arr[i]; //new i
        }
        for(auto x:umap){
            cout<<x.first<<" ";
        }
        umap.clear();
        cout<<"\n";
    }
    return 0;
}
