// Make largest palindrome by changing at most K-digits
// https://www.geeksforgeeks.org/make-largest-palindrome-changing-k-digits/
// Approach:

// 1.Solve this problem using two pointers method. We start from left and right and if both digits are not equal,
// then we replace the smaller value with larger value and decrease k by 1.
// 2. Stop when the left and right pointers cross each other, after they stop if value of k is negative, 
// then it is not possible to make string palindrome using k changes. 
// 3.If k is positive, then we can further maximize the string by looping once again in the same manner from left and right
// and converting both the digits to 9 and decreasing k by 2.
// 4.If k value remains to 1 and string length is odd then we make the middle character as 9 to maximize whole value.


#include<bits/stdc++.h>
#define ll long long int
using namespace std;
string maximumPalinUsingKChanges(string str,int k){
    int n=str.length();
    int l=0;
    int r=n-1;
    string ans(n);
    while(l<r){
         // Replace left and right character by
        // maximum of both
        if(str[l]!=str[r]){
            ans[l]=ans[r]=max(str[l],str[r]);
            k--;
        }
        l++;
        r--;
    }

    // If k is negative then we can't make
    // string palindrome
    if(k<0){
        return "Not Possible";
    }

    l=0;
    r=n-1;
    while(l<=r){
         // At mid character, if K>0 then change
        // it to 9
        if(l==r){
            if(k>0){
                ans[l]='9';
            }
        }

        // If character at lth (same as rth) is
        // less than 9
        if(ans[l]<'9'){
            /* If none of them is changed in the
               previous loop then subtract 2 from K
               and convert both to 9 */
            if(k>=2 && ans[l]==str[l] && ans[r]==str[r]){
                k=k-2;
                ans[l]=ans[r]='9';
            }

             /*  If one of them is changed
                in the previous
                loop then subtract 1 from K
                (1 more is
                subtracted already) and make them 9  */
            else if(k>=1 && (ans[l]!=str[l] || ans[r]!=str[r])){
                k--;
                ans[l]=ans[r]='9';
            }
        }
        l++;
        r--;
    }
    return ans;
}
int main() {
    string str = "43435";
    int k = 3;
    cout << maximumPalinUsingKChanges(str, k);
    return 0;
}
