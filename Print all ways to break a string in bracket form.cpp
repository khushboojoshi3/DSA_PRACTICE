// Print all ways to break a string in bracket form
// https://www.geeksforgeeks.org/print-ways-break-string-bracket-form/
#include<bits/stdc++.h>
using namespace std;
void helper(string str,string ans){
    if(str.length()==0){
        // cout<<"hi\n";
        cout<<ans<<"\n";
        return;
    }
    for(int i=0;i<str.length();i++){
        string fword;
        string sword;
        if(i==str.length()-1){
            fword=str;
            sword="";
        }
        else{
            fword=str.substr(0,i+1);
            sword=str.substr(i+1);
        }
        
        // cout<<fword<<" "<<sword<<"\n";

        helper(sword,ans+"("+fword+")");
    }
}
int main() {
    string str = "abcd";
    helper(str,"");
    return 0;
}
