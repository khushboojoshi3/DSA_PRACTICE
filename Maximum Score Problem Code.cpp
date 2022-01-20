// Maximum Score Problem Code: MAXSC (Codechef)

// Read problems statements in Mandarin chinese, Russian and Vietnamese as well.
// You are given N integer sequences A1, A2, ..., AN. Each of these sequences contains N elements. 
//You should pick N elements, one from each sequence; let's denote the element picked from sequence Ai by Ei. For each i (2 ≤ i ≤ N), Ei should be strictly greater than Ei-1.

// Compute the maximum possible value of E1 + E2 + ... + EN. If it's impossible to pick the elements E1, E2, ..., EN, print -1 instead.


// https://www.youtube.com/watch?v=5N3tQOz4Bhg&t=475s


#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll binary_search(vector<ll> arr,ll ele){
    ll s=0;
    ll n=arr.size();
    ll e=n-1;
    ll index=-1;
    while(s<=e){
        ll mid=(s+e)/2;
        if(arr[mid]==ele){
            index=mid;
            break;
        }
        else if(arr[mid]<ele){
            index=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return index;
}
int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll x;
        vector<vector<ll>> arr(n,vector<ll> (n));
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                cin>>x;
                arr[i][j]=x;
            }
            sort(arr[i].begin(),arr[i].end());
        }

        ll ans=0;
        ll mx=1e18;
        bool possible=true;
        for(ll i=n-1;i>=0 && possible;i--){
            ll idx=binary_search(arr[i],mx);
            if(idx>=0 && idx<n){
                ans+=arr[i][idx];
                mx=arr[i][idx]-1;
            }
            else{
                possible=false;
                break;
            }
        }
        if(possible){
            cout<<ans<<"\n";
        }
        else{
            cout<<"-1\n";
        }
    }
    return 0;
}
