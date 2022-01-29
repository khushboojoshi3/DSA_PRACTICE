// Longest Possible Route in a Matrix with Hurdles
// https://www.geeksforgeeks.org/longest-possible-route-in-a-matrix-with-hurdles/
#include<bits/stdc++.h>
using namespace std;
#define R 3
#define C 10
void helper(int mat[R][C], int i, int j, int x,int y, bool visited[R][C],int curr_len,int &max_path){
    if(i<0 || j<0 || i>=R || j>=C || visited[i][j]==true || mat[i][j]!=1){
        return ;
    }
    if(i==x && j==y){
        max_path=max(curr_len,max_path);
        return;
    }

    visited[i][j]=true;
    helper(mat,i+1,j,x,y,visited,curr_len+1,max_path);
    helper(mat,i-1,j,x,y,visited,curr_len+1,max_path);
    helper(mat,i,j+1,x,y,visited,curr_len+1,max_path);
    helper(mat,i,j-1,x,y,visited,curr_len+1,max_path);
    visited[i][j]=false;
}


void findLongestPath(int mat[R][C], int i, int j, int x,int y)
{
    bool visited[R][C];
 
    // initialize visited to false
    memset(visited, false, sizeof(visited));

    int max_path=INT_MIN;
    int curr_len=0;
    helper(mat, i, j, x, y, visited,curr_len,max_path);
    if (max_path!=INT_MIN)
        cout << "Length of longest possible route is "
             << max_path;
 
    // If the destination is not reachable
    else
        cout << "Destination not reachable from given "
                "source";
}
int main()
{
   int mat[R][C] = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                      { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
                      { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };
 
   
    findLongestPath(mat, 0, 0, 1, 7);
    return 0;
}
