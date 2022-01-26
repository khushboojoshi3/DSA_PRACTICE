// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
// Repeated subsequence of length 2 or more
#include<bits/stdc++.h>
using namespace std;
string longestRepeatingSubsequence(string str){
    int n=str.length();
    string dp[n+1][n+1];
    string str1=str;
    string str2=str;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                dp[i][j]="";
            }
            else if(i!=j && str1[i-1]==str2[j-1]){
                dp[i][j]=dp[i-1][j-1]+str1[i-1];
            }
            else{
                dp[i][j]= dp[i-1][j].length()>dp[i][j-1].length() ? dp[i-1][j] : dp[i][j-1];
            }
        }
    }
    if(dp[n][n].length()<2){
        return "Required longest repeating subsequence doesn't exist";
    }
    else{
        return dp[n][n];
    }
}
int main(){
    int n=6;
    string words[]={"abcabd","abbb","aab","aabbc","abcdacb","abcd"};
    for(int i=0;i<n;i++){
        cout<<longestRepeatingSubsequence(words[i])<<"\n";
    }
    return 0;
}
