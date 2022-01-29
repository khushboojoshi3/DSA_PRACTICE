// Print all palindromic partitions of a string
// https://leetcode.com/problems/palindrome-partitioning/
// Input  : s = "bcc"
// Output : [["b", "c", "c"], ["b", "cc"]]

// Input  : s = "geeks"
// Output : [["g", "e", "e", "k", "s"], 
//           ["g", "ee", "k", "s"]]


class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string str){
        int i=0;
        int n=str.length();
        int j=n-1;
        while(i<=j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void helper(string str,vector<string> sans){
        if(str.size()==0){
            ans.push_back(sans);
            return ;
        }
        for(int i=0;i<str.size();i++){
            string fword=str.substr(0,i+1);
            string sword=str.substr(i+1);
            if(isPalindrome(fword)){
                sans.push_back(fword);
                helper(sword,sans);
                sans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> sans;
        helper(s,sans);
        return ans;
    }
};
