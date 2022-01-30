// Minimum cost for acquiring all coins with k extra coins allowed with every coin
// https://www.geeksforgeeks.org/minimum-cost-for-acquiring-all-coins-with-k-extra-coins-allowed-with-every-coin/
// You are given a list of N coins of different denominations. You can pay an amount equivalent to any 1 coin and can acquire that coin. In addition, once you have paid for a coin, we can choose at most K more coins and can acquire those for free. The task is to find the minimum amount required to acquire all the N coins for a given value of K.

// Examples : 

// Input : coin[] = {100, 20, 50, 10, 2, 5}, 
//         k = 3
// Output : 7

// Input : coin[] = {1, 2, 5, 10, 20, 50}, 
//         k = 3
// Output : 3
#include<bits/stdc++.h>
using namespace std;
 
// function to calculate min cost
int minCost(int coin[], int n, int k)
{
    sort(coin,coin+n);
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=coin[i];
        n=n-k;
    }
    return ans;
}
int main()
{
    // int coin[] = {8, 5, 3, 10,
    //               2, 1, 15, 25};
    int coin[]={100, 20, 50, 10, 2, 5};
    int n = sizeof(coin) / sizeof(coin[0]);
    int k = 3;
    cout << minCost(coin, n, k);
    return 0;
}
