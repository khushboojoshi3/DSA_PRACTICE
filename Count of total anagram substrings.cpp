// Count of total anagram substrings
// https://www.geeksforgeeks.org/count-total-anagram-substrings/

// Input  : str = “xyyx”
// Output : 4
// Total substrings of this string which
// are anagram to each other are 4 which 
// can be enumerated as,
// {“x”, “x”}, {"y", "y"}, {“xy”, “yx”}, 
// {“xyy”, “yyx”}

// Input  : str = "geeg"
// Output : 4

#include <bits/stdc++.h>
using namespace std;


int countOfAnagramSubstring(string str)
{
    int N=str.length();
    map<vector<int>,int> mp;
    for(int i=0;i<N;i++){
        vector<int> freq(26,0);
        for(int j=i;j<N;j++){
            freq[str[j]-'a']++;
            mp[freq]++;
        }
        
    }

    int ans=0;
    for(auto x:mp){
        int freq=x.second;
        ans+=(freq*(freq-1))/2;
    }
    return ans;
}
int main() {
    string str = "xyyx";
    cout << countOfAnagramSubstring(str) << endl;
    return 0;
}
