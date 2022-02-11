// https://www.geeksforgeeks.org/count-natural-numbers-whose-permutation-greater-number/
// Count natural numbers whose all permutation are greater than that number
// There are some natural number whose all permutation is greater than or equal to that number
// eg. 123, whose all the permutation (123, 231, 321) are greater than or equal to 123. 
// Given a natural number n, the task is to count all such number from 1 to n. 
#include <bits/stdc++.h>
using namespace std;

// Return the count of the number having all
// permutation greater than or equal to the number.
int countNumber(int n)
{
    stack<int> st;
    int res=0;
    for(int i=1;i<=9;i++){
        if(i<=n){
            st.push(i);
            res++;
        }

        while(!st.empty()){
            int tp=st.top();
            st.pop();
            for(int j=tp%10;j<=9;j++){
                int x=tp*10+j;
                if(x<=n){
                    st.push(x);
                    res++;
                }
            }
        }
    }
    return res;
}
int main()
{
    int n = 15;
    cout << countNumber(n) << endl;
    return 0;
}
