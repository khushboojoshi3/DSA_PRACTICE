// Find k’th character of decrypted string 
// https://www.geeksforgeeks.org/find-kth-character-of-decrypted-string/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
char encodedChar(string str,int k)
{
    string ans;
    string temp;
    ll freq=0;
    for(ll i=0;i<str.length();){
        temp="";
        freq=0;
        while(str[i]>='a' && str[i]<='z'){
            temp.push_back(str[i]);
            i++;
        }
        while (str[i]>='1' && str[i]<='9')
        {
            // generating frequency of temp
            freq = freq*10 + str[i] - '0';
            i++;
        }
        for(ll j=1;j<=freq;j++){
            ans+=temp;
        }
    }
    // this condition is to handle the case
    // when string str is ended with alphabets
    // not with numeric value
    if(freq==0){
        ans+=temp;
    }
    // cout<<ans<<"\n";
    return ans[k-1];
}

int main(){
    string str = "ab4c12ed3";
    int k = 21;
    cout << encodedChar(str, k) << endl;
    return 0;
}
