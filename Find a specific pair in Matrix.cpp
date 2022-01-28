// https://www.geeksforgeeks.org/find-a-specific-pair-in-matrix/
// Find a specific pair in Matrix
// Given an n x n matrix mat[n][n] of integers,
// find the maximum value of mat(c, d) – mat(a, b) over all choices of indexes such that both c > a and d > b.
#include <bits/stdc++.h>
using namespace std;
#define N 5
 
// The function returns maximum value A(c,d) - A(a,b)
// over all choices of indexes such that both c > a
// and d > b.
int findMaxValue(int mat[][N])
{
    int maxValue=INT_MIN;
    // maxArr[i][j] stores max of elements in matrix
    // from (i, j) to (N-1, N-1)
    int maxArr[N][N];
    maxArr[N-1][N-1]=mat[N-1][N-1];
    int maxv=maxArr[N-1][N-1];
    //preprocess the last row
    for(int j=N-2;j>=0;j--){
        if(maxv<mat[N-1][j]){
            maxv=mat[N-1][j];
        }
        maxArr[N-1][j]=maxv;
    }

    //preprocess the last column
    for(int i=N-2;i>=0;i--){
        if(maxv<mat[i][N-1]){
            maxv=mat[i][N-1];
        }
        maxArr[i][N-1]=maxv;
    }

    for(int i=N-2;i>=0;i--){
        for(int j=N-2;j>=0;j--){
            if(maxArr[i+1][j+1]-mat[i][j]>maxValue){
                maxValue=maxArr[i+1][j+1]-mat[i][j];
            }
            maxArr[i][j]=max(mat[i][j],max(maxArr[i+1][j],maxArr[i][j+1]));
        }
    }
    return maxValue;
}

int main()
{
    int mat[N][N] = {
                      { 1, 2, -1, -4, -20 },
                      { -8, -3, 4, 2, 1 },
                      { 3, 8, 6, 1, 3 },
                      { -4, -1, 1, 7, -6 },
                      { 0, -4, 10, -5, 1 }
                    };
    cout << "Maximum Value is "
         << findMaxValue(mat);
 
    return 0;
}
