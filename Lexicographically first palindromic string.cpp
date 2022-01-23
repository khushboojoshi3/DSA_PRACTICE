// https://www.geeksforgeeks.org/lexicographically-first-palindromic-string/
// Lexicographically first palindromic string
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll freq[26]={0};
ll odd_count=0;
char odd_character;
bool palindromePossible(string str){
    for(int i=0;i<str.length();i++){
        freq[str[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(freq[i]%2==1){
            odd_count++;
            odd_character=i+'a';
        }
        if(odd_count>=2){
            return false;
        }
    }
    return true;
}
string findPalindromicString(string str)
{
    bool possible=palindromePossible(str);
    if(possible==false){
        return "No Palindromic String";
    }
    ll n=str.length();
    string ans;
    ans.resize(n);
    ll start_idx=0;
    ll end_idx=n-1;
    for(ll j=0;j<26;j++){
        ll count=freq[j];
        if(count%2==1){
            continue;
        }
        char ch=j+'a';
        while(count>0){
           ans[start_idx]=ch;
           ans[end_idx]=ch;
           start_idx++;
           end_idx--;
           count=count-2;
        }   
    }

    if(odd_count==1){
        ll count=freq[odd_character-'a'];
        while(count){
            ans[start_idx]=odd_character;
            start_idx++;
            count--;
        }
    }
    // cout<<"hi\n";
    // cout<<ans<<"\n";
    return ans;
}
int main() {
    string str = "malayalam";
    cout << findPalindromicString(str);
    return 0;
}
