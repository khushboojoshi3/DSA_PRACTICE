// https://www.geeksforgeeks.org/find-common-element-rows-row-wise-sorted-matrix/
// Find a common element in all rows of a given row-wise sorted matrix
// Given a matrix where every row is sorted in increasing order. 
// Write a function that finds and returns a common element in all rows. 
// If there is no common element, then returns -1. 
#include <bits/stdc++.h>
using namespace std;
 
// Specify number of rows and columns
#define M 4
#define N 5

int findCommon(int mat[M][N])
{
    unordered_map<int,int> cnt;
    
    for(int i=0;i<M;i++){
        cnt[mat[0][0]]++;
        for(int j=1;j<N;j++){
            if(mat[i][j-1]!=mat[i][j]){
                cnt[mat[i][j]]++;
        }
    }
    }
    for(auto x:cnt){
        if(x.second==M){
            return x.first;
        }
    }
    return -1;
}

int main()
{
    int mat[M][N] = {
        { 1, 2, 3, 4, 5 },
        { 2, 4, 5, 8, 10 },
        { 3, 5, 7, 9, 11 },
        { 1, 3, 5, 7, 9 },
    };
    int result = findCommon(mat);
    if (result == -1)
        cout << "No common element";
    else
        cout << "Common element is " << result;
 
    return 0;
}
