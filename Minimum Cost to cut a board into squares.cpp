// Minimum Cost to cut a board into squares
// A board of length m and width n is given, we need to break this board into m*n squares,
// such that cost of breaking is minimum. cutting cost for each edge will be given for the board.
// In short, we need to choose such a sequence of cutting such that cost is minimized. 

// https://www.geeksforgeeks.org/minimum-cost-cut-board-squares/
// https://www.youtube.com/watch?v=9DckVBRzuQU
#include <bits/stdc++.h>
using namespace std;
  
// method returns minimum cost to break board into
// m*n squares
int minimumCostOfBreaking(int X[], int Y[], int m, int n)
{
    int ans=0;
    sort(X,X+m,greater<int>());
    sort(Y,Y+n,greater<int>());
    int hrzntl=1; //horizontal pieces
    int vrtcl=1; //vertical pieces
    int i=0;
    int j=0;
    while(i<m && j<n){
        if(X[i]>Y[j]){
            ans=ans+X[i]*vrtcl;
            hrzntl++;
            i++;
        }
        else{
            ans=ans+Y[j]*hrzntl;
            vrtcl++;
            j++;
        }
    }

    while(i<m){
        ans=ans+X[i]*vrtcl;
        i++;
        hrzntl++;
    }
    while(j<n){
        ans=ans+Y[j]*hrzntl;
        j++;
        vrtcl++;
    }
    return ans;
}
int main()
{
    int m = 6, n = 4;
    int X[m-1] = {2, 1, 3, 1, 4};
    int Y[n-1] = {4, 1, 2};
    cout << minimumCostOfBreaking(X, Y, m-1, n-1);
    return 0;
}
