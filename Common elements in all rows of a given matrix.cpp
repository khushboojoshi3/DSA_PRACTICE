// Common elements in all rows of a given matrix
// https://www.geeksforgeeks.org/find-common-element-rows-row-wise-sorted-matrix/
// Given a matrix where every row is sorted in increasing order.
// Write a function that finds and returns a common element in all rows.
// If there is no common element, then returns -1. 
#include <bits/stdc++.h>
using namespace std;
 
// Specify number of rows and columns
#define M 4
#define N 5

void printCommonElements(int mat[M][N])
{
    unordered_map<int,int> cnt;
    for(int j=0;j<N;j++){
        cnt[mat[0][j]]=1;
    }
    for(int i=1;i<M;i++){
        for(int j=0;j<N;j++){
            // If element is present in the map and
            // is not duplicated in current row.
            if(cnt[mat[i][j]]==i){
                cnt[mat[i][j]]++;
                //if this is the last row
                if(i==M-1 && cnt[mat[i][j]]==M){
                    cout<<mat[i][j]<<" ";
                }
            }
        }
    }
}

int main()
{
   int mat[M][N] =
    {
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9},
    };
 
    printCommonElements(mat);
 
 
    return 0;
}
