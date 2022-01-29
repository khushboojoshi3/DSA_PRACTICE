//Remove Invalid Parentheses
// https://www.geeksforgeeks.org/remove-invalid-parentheses/
// https://leetcode.com/problems/remove-invalid-parentheses/

// Input  : str = “()())()” -
// Output : ()()() (())()
// There are two possible solutions
// "()()()" and "(())()"

// Input  : str = (v)())()
// Output : (v)()()  (v())()

class Solution {
public:
    vector<string> ans;
    unordered_set<string> uset;
    int countRemovals(string s){
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push('(');
            }
            else if(s[i]==')'){
                if(st.size()==0){
                    st.push(')');
                }
                else if(st.top()==')'){
                    st.push(')');
                }
                else if(st.top()=='('){
                    st.pop();
                }
            }
        }
        int invalid=st.size();
        return invalid;
    }
    
    void helper(int invalid,string str){
        if(invalid==0){
            int invalidNow=countRemovals(str);
            if(invalidNow==0){
                ans.push_back(str);
            }
            return ;
        }
        
        for(int i=0;i<str.size();i++){
            if(str[i]!='(' && str[i]!=')'){
                continue;
            }
            //removing the ith character
            string left=str.substr(0,i);
            string right=str.substr(i+1);
            string temp=left+right;
            if(uset.find(temp)==uset.end()){
                uset.insert(temp);
                helper(invalid-1,temp);
            }
        }
    }
    vector<string> removeInvalidParentheses(string str) {
        int invalid=countRemovals(str);
        helper(invalid,str);
        return ans;
    }
};
