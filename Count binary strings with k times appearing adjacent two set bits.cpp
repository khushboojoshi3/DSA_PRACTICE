// https://www.geeksforgeeks.org/count-binary-strings-k-times-appearing-adjacent-two-set-bits/
// Count binary strings with k times appearing adjacent two set bits
// Given two integers n and k, count the number of binary strings of length n with k as number of times adjacent 1’s appear.

// Examples: 

// Input  : n = 5, k = 2
// Output : 6
// Explanation:
// Binary strings of length 5 in which k number of times
// two adjacent set bits appear.
// 00111  
// 01110
// 11100
// 11011
// 10111
// 11101

// Input  : n = 4, k = 1
// Output : 3
// Explanation:
// Binary strings of length 3 in which k number of times
// two adjacent set bits appear.
// 0011  
// 1100
// 0110

#include <bits/stdc++.h>
using namespace std;
long long int dp[1001][1001][2];
long long int mod = 1e9 + 7;
long long int helper(int n,int k,int endingWith){
    // if(i==n && j==k && endingWith)
    if(n==0){
        return 0;
    }
    if(n==1 && k==0){
        return 1;
    }
    if(dp[n][k][endingWith]!=-1){
        return dp[n][k][endingWith];
    }
    int total=0;
    if(endingWith==0){
        total=(total%mod + helper(n-1,k,0)%mod + helper(n-1,k,1)%mod)%mod; //if I am adding '0' at the end this time
    }
    if(endingWith==1)
    {
        total=(total%mod + helper(n-1,k,0)%mod + helper(n-1,k-1,1)%mod)%mod; //if I am adding '1' at the end this time
    }
    return dp[n][k][endingWith]=total;
}
 int countStrings(int n, int k)
    {
        
       
        memset(dp,-1,sizeof(dp));
        long long int val1=helper(n,k,0);
        long long int val2=helper(n,k,1);
        return (val1+val2);
    }
int main() {
    int n = 3, k = 2;
    memset(dp,-1,sizeof(dp));
    
    cout<<countStrings(n,k)<<"\n";
    return 0;
}
