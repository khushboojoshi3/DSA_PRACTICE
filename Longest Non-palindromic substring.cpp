// Longest Non-palindromic substring
// https://www.geeksforgeeks.org/longest-non-palindromic-substring/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool isPalindrome(string str){
    int n=str.length();
    int i=0;
    int j=n-1;
    while(i<=j){
        if(str[i]==str[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}
int maxLengthNonPalinSubstring(string str)
{
    int n=str.length();
    char ch=str[0];
    int i=1;
    // to check whether all characters
    // of the string are same or not
    for(i=1;i<n;i++){
        if(ch!=str[i]){
            break;
        }
    }

    // All characters are same, we can't
    // make a non-palindromic string.
    if(i==n){
        return 0;
    }

    // If string is palindrome, we can make
    // it non-palindrome by removing any
    // corner character
    if (isPalindrome(str))
        return n-1;
 
    // Complete string is not a palindrome.
    return n;
}
int main() {
    string str = "abba";
    cout << "Maximum length = "
         << maxLengthNonPalinSubstring(str);
    return 0;
}
