// Printing Shortest Common Supersequence
// https://leetcode.com/problems/shortest-common-supersequence/submissions/
// https://www.youtube.com/watch?v=pHXntFeu6f8
class Solution {
public:
    string findLCS(string str1,string str2){
        int m=str1.length();
        int n=str2.length();
        vector<vector<string>> dp(m+1,vector<string> (n+1));
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0){
                    dp[i][j]="";
                }
                else if(str1[i-1]==str2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+str1[i-1];
                }
                else{
                    dp[i][j]=dp[i-1][j].size() > dp[i][j-1].size() ? dp[i-1][j] : dp[i][j-1]; 
                }
            }
        }
        return dp[m][n];
    }
    string shortestCommonSupersequence(string str1, string str2) {
        string lcs=findLCS(str1,str2);
        // cout<<lcs;
        string ans;
        int ptr1=0;
        int ptr2=0;
        for(char ch:lcs){
            while(str1[ptr1]!=ch){
                ans+=str1[ptr1];
                ptr1++;
            }
            while(str2[ptr2]!=ch){
                ans+=str2[ptr2];
                ptr2++;
            }
            ans+=ch;
            ptr1++;
            ptr2++;
        }
        ans=ans+str1.substr(ptr1)+str2.substr(ptr2);  //if anything is left in str1 and str2 that will be added at this step
        return ans;
    }
};
