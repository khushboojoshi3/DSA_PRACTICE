// Check a given sentence for a given set of simple grammar rules
// https://www.geeksforgeeks.org/check-given-sentence-given-set-simple-grammer-rules/
#include<bits/stdc++.h>
using namespace std;
bool checkSentence(string str)
{   
    int len=str.length();
    if(str[0]<'A' || str[0]>'Z'){
        return false;
    }
    if(str[len-1]!='.'){
        return false;
    }
    
    int curr_state=0;
    int prev_state=0;
    int index=1;
    while(str[index]){
        if(str[index]>='A' && str[index]<='Z'){
            curr_state=0;
        }
        else if(str[index]==' '){
            curr_state=1;
        }
        else if(str[index]>='a' && str[index]<='z'){
            curr_state=2;
        }
        else if(str[index]=='.'){
            curr_state=3;
        }
        if(curr_state==prev_state && curr_state!=2){
            return false;
        }
        if(curr_state==0 && prev_state==2){
            return false;
        }
        // If we have reached last state and previous state is not 1,
        // then check next character. If next character is '\0', then
        // return true, else false
        if(curr_state==3 && prev_state!=1){
            return (str[index+1]=='\0');
        }
        index++;
        prev_state=curr_state;

    }
    return false;
}
int main() {
    string str[] = { "I love cinema.", "The vertex is S.",
                    "I am single.", "My name is KG.",
                    "I lovE cinema.", "GeeksQuiz. is a quiz site.",
                    "I love Geeksquiz and Geeksforgeeks.",
                    "  You are my friend.", "I love cinema" };
    int str_size = sizeof(str) / sizeof(str[0]);
    int i = 0;
    for (i = 0; i < str_size; i++){
        if(checkSentence(str[i])){
         cout<<"YES\n";
     }
     else
     {
         cout<<"NO\n";
     }
    }
     
    return 0;
}
