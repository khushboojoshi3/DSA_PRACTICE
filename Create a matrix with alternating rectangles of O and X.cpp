// Create a matrix with alternating rectangles of O and X
// https://www.geeksforgeeks.org/create-a-matrix-with-alternating-rectangles-of-0-and-x/
#include <bits/stdc++.h>
using namespace std;
 
// Function to print alternating rectangles of 0 and X
void fill0X(int m, int n)
{
    vector<vector<char>> arr(m,vector<char> (n));
    int T=0;
    int B=m-1;
    int L=0;
    int i,j;
    char x='x';
    int R=n-1;
    while(T<=B && L<=R){
    
        for(i=L;i<=R;i++){
            arr[T][i]=x;
        }
        T++;
        
        //bcz above values of R and T and changed that's why we are checking again
        if(T<=B && L<=R){
            for(i=T;i<=B;i++){
            arr[i][R]=x;
        }
        R--;
        }
        

        if(L<=R && T<=B){
            for(i=R;i>=L;i--){
            arr[B][i]=x;
            }
            B--;
        }
        
        if(T<=B && L<=R){
            for(i=B;i>=T;i--){
                arr[i][L]=x;
            }
            L++;
        }
        if(x=='x'){
            x='o';
        }
        else{
            x='x';
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main() {
     puts("Output for m = 5, n = 6");
    fill0X(5, 6);
 
    puts("\nOutput for m = 4, n = 4");
    fill0X(4, 4);
 
    puts("\nOutput for m = 3, n = 4");
    fill0X(3, 4);
 
    return 0;
}
