// Find paths from corner cell to middle cell in maze
// https://www.geeksforgeeks.org/find-paths-from-corner-cell-to-middle-cell-in-maze/
#include<bits/stdc++.h>
using namespace std;
#define N 9
// Input:  9 x 9 maze
// [ 3, 5, 4, 4, 7, 3, 4, 6, 3 ]
// [ 6, 7, 5, 6, 6, 2, 6, 6, 2 ]
// [ 3, 3, 4, 3, 2, 5, 4, 7, 2 ]
// [ 6, 5, 5, 1, 2, 3, 6, 5, 6 ]
// [ 3, 3, 4, 3, 0, 1, 4, 3, 4 ]
// [ 3, 5, 4, 3, 2, 2, 3, 3, 5 ]
// [ 3, 5, 4, 3, 2, 6, 4, 4, 3 ]
// [ 3, 5, 1, 3, 7, 5, 3, 6, 4 ]
// [ 6, 2, 4, 3, 4, 5, 4, 5, 1 ]

// Output:
// (0, 0) -> (0, 3) -> (0, 7) -> 
// (6, 7) -> (6, 3) -> (3, 3) -> 
// (3, 4) -> (5, 4) -> (5, 2) -> 
// (1, 2) -> (1, 7) -> (7, 7) ->
// (7, 1) -> (2, 1) -> (2, 4) -> 
// (4, 4) -> MID

// Driver code

void printPath(int maze[N][N],int i,int j,string path){
    if(i==N/2 && j==N/2){
        cout<<path<<"("<<i<<", "<<j<<") -> MID";
        cout<<"\n";
        return ;
    }

    // If the element at the current position
    // in maze is 0, simply Return as it has
    // been visited before.
    if(maze[i][j]==0){
        return ;
    }
    int n=maze[i][j];
    maze[i][j]=0;
    if(i-n>=0){
        printPath(maze,i-n,j,path+"("+to_string(i)+", "+to_string(j)+") -> ");
    }
    if(i+n<N){
        printPath(maze,i+n,j,path+"("+to_string(i)+", "+to_string(j)+") -> ");
    }
    if(j-n>=0){
        printPath(maze,i,j-n,path+"("+to_string(i)+", "+to_string(j)+") -> ");
    }
    if(j+n<N){
        printPath(maze,i,j+n,path+"("+to_string(i)+", "+to_string(j)+") -> ");
    }
    //backtrack
    maze[i][j]=n;
}
int main()
{
    int maze[N][N] =
    {
        { 3, 5, 4, 4, 7, 3, 4, 6, 3 },
        { 6, 7, 5, 6, 6, 2, 6, 6, 2 },
        { 3, 3, 4, 3, 2, 5, 4, 7, 2 },
        { 6, 5, 5, 1, 2, 3, 6, 5, 6 },
        { 3, 3, 4, 3, 0, 1, 4, 3, 4 },
        { 3, 5, 4, 3, 2, 2, 3, 3, 5 },
        { 3, 5, 4, 3, 2, 6, 4, 4, 3 },
        { 3, 5, 1, 3, 7, 5, 3, 6, 4 },
        { 6, 2, 4, 3, 4, 5, 4, 5, 1 }
    };
    printPath(maze,0,0,"");
    return 0;
}
