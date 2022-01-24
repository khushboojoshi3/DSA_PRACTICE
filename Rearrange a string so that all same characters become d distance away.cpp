// Rearrange a string so that all same characters become d distance away
// https://www.geeksforgeeks.org/rearrange-a-string-so-that-all-same-characters-become-at-least-d-distance-away/
#include<bits/stdc++.h>
using namespace std;
class comp{
    public:
    bool operator()(pair<char,int> a,pair<char,int> b){
    if(a.second==b.second){
        return a.first>b.first;
    }
    return a.second<b.second;
}
};

string rearrange(string str,int d){
    int n=str.length();
    unordered_map<char,int> umap;
    for(char ch:str){
        umap[ch]++;
    }
    priority_queue<pair<char,int>,vector<pair<char,int>>,comp> pq;
    for(auto x:umap){
        pq.push({x.first,x.second});
    }
    int size=n;
    string ans;
    while(size--){
        ans+='*';
    }
    
    while(!pq.empty()){
        char ch=pq.top().first;
        int freq=pq.top().second;
        pq.pop();
        int ptr=0;
        while(ans[ptr]!='*'){
            ptr++;
        }
        
        for(int k=0;k<freq;k++){
            if(ptr+k*d>=n){
                return "Cannot be rearranged";
            }
            ans[ptr+k*d]=ch;
        }
        ptr++;
    }
    return ans;
}
int main(){
    string str="aacbbc";
    string ans=rearrange(str,3);
    cout<<ans;
    return 0;
}
