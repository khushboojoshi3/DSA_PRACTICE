// https://www.geeksforgeeks.org/binary-representation-next-greater-number-number-1s-0s/
// Binary representation of next greater number with same number of 1’s and 0’s
// This problem simply boils down to finding next permutation of a given string.
#include<bits/stdc++.h>
using namespace std;
string nextGreaterWithSameDigits(string num)
{
    int n=num.length();
    int k,l;
    for(k=n-2;k>=0;k--){
        if(num[k]<num[k+1]){
            break;
        }
    }
    if(k<0){
        return "No greater Number";
    }

    for(l=n-1;l>k;l--){
        if(num[l]>num[k]){
            break;
        }
    }
    swap(num[l],num[k]);
    reverse(num.begin()+k+1,num.end());
    return num;
}
int main()
{
    string bnum = "10010";
    cout << "Binary representation of next greater number = "
         << nextGreaterWithSameDigits(bnum);
    return 0;
}
