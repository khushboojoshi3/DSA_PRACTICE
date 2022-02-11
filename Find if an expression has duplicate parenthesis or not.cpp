// https://www.geeksforgeeks.org/find-expression-duplicate-parenthesis-not/
// Find if an expression has duplicate parenthesis or not
// Given a balanced expression, find if it contains duplicate parenthesis or not.
// A set of parenthesis are duplicate if the same subexpression is surrounded by multiple parenthesis. 
#include <bits/stdc++.h>
using namespace std;
 
// Function to find duplicate parenthesis in a
// balanced expression
bool findDuplicateparenthesis(string str){
    stack<char> st;
    for(char ch:str){
        if(ch==')'){
            char top=st.top();
            st.pop();
            int elementsBetweenBrackets=0;
            while(top!='('){
                elementsBetweenBrackets++;
                top=st.top();
                st.pop();
            }
            if(elementsBetweenBrackets<1){
                return true;//brackets are redundant or less
            }
        }
        else{
            st.push(ch);
        }
    }
    return false;
}
int main()
{
    // input balanced expression
    string str = "(((a+(b))+(c+d)))";
 
    if (findDuplicateparenthesis(str))
        cout << "Duplicate Found ";
    else
        cout << "No Duplicates Found ";
 
    return 0;
}
