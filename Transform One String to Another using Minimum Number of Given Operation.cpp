// Transform One String to Another using Minimum Number of Given Operation
// https://www.geeksforgeeks.org/transform-one-string-to-another-using-minimum-number-of-given-operation/
// Checking whether a string can be transformed to another is simple. 
// We need to check whether both strings have same number of characters and same set of characters.
// This can be easily done by creating a count array for first string and
// checking if second string has same count of every character. 

// How to find minimum number of operations when we are sure that we can transform A to B? 
// The idea is to start matching from last characters of both strings.
// If last characters match, then our task reduces to n-1 characters. 
// If last characters don’t match, then find the position of B’s mismatching character in A.
// The difference between two positions indicates that these many characters of A must be moved before current character of A.


// If current characters don’t match, then search B[j] in remaining 
// ………A. While searching, keep incrementing result as these characters 
// ………must be moved ahead for A to B transformation.
#include<bits/stdc++.h>
using namespace std;
int minOps(string A, string B)
{
    int n=A.length();
    int m=B.length();
    if(n!=m) return -1;
    int count[256]={0};
    for(char ch:A){
        count[ch]++;
    }
    for(char ch:B){
        count[ch]--;
    }
    for(int i=0;i<256;i++){
        if(count[i]!=0){
            return -1;
        }
    }
    int res=0;
    int i=n-1;
    int j=n-1;
    while(i>=0 && j>=0){
        if(A[i]==B[j]){
            i--;
            j--;
        }
        else{
            while(i>=0 && A[i]!=B[j]){
                i--;
                res++;
            }
        }
    }
    return res;
}
int main() {
    string A = "EACBD";
    string B = "EABCD";
    cout << "Minimum number of operations "
            "required is " << minOps(A, B);
    return 0;
}
