// Recursively print all sentences that can be formed from list of word lists
// https://www.geeksforgeeks.org/recursively-print-all-sentences-that-can-be-formed-from-list-of-word-lists/
#include<bits/stdc++.h>
#define R 3
#define C 3
using namespace std;
void helper(string arr[R][C],int m,int n,string output[R]){
    output[m]=arr[m][n];
    if(m==R-1){
        for(int i=0;i<R;i++){
            cout<<output[i]<<" ";
        }
        cout<<"\n";
        return ;
    }

    for(int j=0;j<C;j++){
        if(arr[m+1][j]!="") helper(arr,m+1,j,output);
    }
}

void print(string arr[R][C])
{
   // Create an array to store sentence
   string output[R];

   // Consider all words for first row as starting points and
   // print all sentences
   for(int j=0;j<C;j++){
       if(arr[0][j]!=""){
           helper(arr,0,j,output);
       }
   }
}
int main(){
    string arr[R][C]  = {{"you", "we"},
                        {"have", "are"},
                        {"sleep", "eat", "drink"}};
    print(arr);
    return 0;
}
