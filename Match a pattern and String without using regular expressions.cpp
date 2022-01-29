// Match a pattern and String without using regular expressions
// https://www.geeksforgeeks.org/match-a-pattern-and-string-without-using-regular-expressions/
#include<bits/stdc++.h>
using namespace std;

bool helper(string str,int n,int i,string pat,int m,int j,unordered_map<char,string> &umap){
    if(i==n && j==m){
        return true;
    }
    if(i==n || j==m){
        return false;
    }
    char ch=pat[j];
    if(umap.find(ch)!=umap.end()){
        string s=umap[ch];
        int len=s.length();
        string subStr=str.substr(i,len);
        if(subStr.compare(s)!=0){
            // if next len characters of string str
        // don't match with s, return false
            return false;
        }
        return helper(str,n,i+len,pat,m,j+1,umap);
    }

    for(int len=1;len<=n-i;len++){
        umap[ch]=str.substr(i,len);
        if(helper(str,n,i+len,pat,m,j+1,umap)){
            return true;
        }
        umap.erase(ch);
    }
    return false;
}
bool patternMatch(string str, string pat, int n, int m)
{
    if (n < m)
    return false;
 
    // create an empty hashmap
    unordered_map<char, string> umap;
 
    // store result in a boolean variable res
    bool res = helper(str, n, 0, pat, m, 0, umap);
 
    // if solution exists, print the mappings
    for (auto x:umap)
        cout << x.first << "->" << x.second << endl;
 
    // return result
    return res;
}
 
// Driver code
int main()
{
    string str = "GeeksforGeeks", pat = "GfG";
 
    int n = str.size(), m = pat.size();
 
    if (!patternMatch(str, pat, n, m))
        cout << "No Solution exists";
 
    return 0;
}
