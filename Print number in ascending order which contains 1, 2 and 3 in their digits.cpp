// Print number in ascending order which contains 1, 2 and 3 in their digits.
// https://www.geeksforgeeks.org/print-number-ascending-order-contains-1-2-3-digits/
#include<bits/stdc++.h>
using namespace std;
bool findContainsOneTwoThree(int number)
{
    int ones=0;
    int twos=0;
    int threes=0;
    string str=to_string(number);
    for(int i=0;i<str.length();i++){
        if(str[i]=='1'){
            ones++;
        }
        else if(str[i]=='2'){
            twos++;
        }
        else if(str[i]=='3'){
            threes++;
        }
    }
    return (ones && twos && threes);
}

string printNumbers(int numbers[], int n)
{
    vector<int> oneTwoThree;
    for(int i=0;i<n;i++){
        if(findContainsOneTwoThree(numbers[i])==true){
            oneTwoThree.push_back(numbers[i]);
        }
    }
    sort(oneTwoThree.begin(),oneTwoThree.end());
    string res="";
    for(auto x:oneTwoThree){
        int val=x;
        if(res.length()>0){
            res+=", ";
        }
        res+=to_string(val);
    }
    return (res.length()>0) ? res : "-1";
}
int main(){
    int numbers[] = { 123, 1232, 456, 234, 32145 };
  
    int n = sizeof(numbers)/sizeof(numbers[0]);
      
    string result = printNumbers(numbers, n);
    cout << result;
    return 0;
}
