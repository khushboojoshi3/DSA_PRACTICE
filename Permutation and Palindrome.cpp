// https://www.codechef.com/FEB18/problems/PERMPAL
// Permutation and Palindrome Problem Code: PERMPAL
// https://www.youtube.com/watch?v=CeYGP8BkVo4
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        ll n=str.length();
        vector<ll> count(26,0);
        // string ans;
        // ans.resize(n);
        vector<int> ans(n);
        vector<vector<ll>> positions(26);
        for(ll i=0;i<n;i++){
            count[str[i]-'a']++;
            positions[str[i]-'a'].push_back(i);
        }

        ll odd_count=0;
        char odd_character;
        bool possible=true;
        for(ll i=0;i<26;i++){
            if(positions[i].size()%2==1){
                odd_count++;
                odd_character=i+'a';
            }
            if(odd_count>=2){
                possible=false;
                break;
            }
        }
        if(possible==false){
            cout<<"-1\n";
        }
        else{
            ll start_idx=0;
            ll end_idx=n-1;
            for(int i=0;i<26;i++){
                int size=positions[i].size();
                if(size%2==0){
                    for(int j=0;j<size;j=j+2){
                        ans[start_idx]=positions[i][j]+1;
                        ans[end_idx]=positions[i][j+1]+1;
                        start_idx++;
                        end_idx--;
                    }
                }
            }

            if(odd_count==1){
                for(int j=0;j<positions[odd_character-'a'].size();j++){
                    ans[start_idx]=positions[odd_character-'a'][j]+1;
                    start_idx++;
                }
            }
            for(int i=0;i<n;i++){
                cout<<ans[i]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
