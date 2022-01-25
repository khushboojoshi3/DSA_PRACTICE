// Function to find Number of customers who could not get a computer
// https://www.geeksforgeeks.org/function-to-find-number-of-customers-who-could-not-get-a-computer/
#include<bits/stdc++.h>
using namespace std;
int runCustomerSimulation(int k, string seq)
{
    int n=seq.length();
    int seen[26]={0};
    int res=0;
    int occupied=0;
    for(int i=0;i<n;i++){
        int ind=seq[i]-'A';
        // If First occurrence of 'seq[i]'
        if(seen[ind]==0){

            // set the current character as seen
            seen[ind]=1;
            // If number of occupied computers is less than
            // n, then assign a computer to new customer
            if(occupied<k){
                occupied++;
                // Set the current character as occupying a computer
                seen[ind]=2;
            }
            // Else this customer cannot get a computer,
            // increment result
            else
              {
                  res++;
              } 

        }
        else{
            // Decrement occupied only if this customer
           // was using a computer
           if(seen[ind]==2){
               occupied--;
           }
           seen[ind]=0;
        }
    }
    return res;
}
int main() {
    cout << runCustomerSimulation(2, "ABBAJJKZKZ") << endl;
    cout << runCustomerSimulation(3, "GACCBDDBAGEE") << endl;
    cout << runCustomerSimulation(3, "GACCBGDDBAEE") << endl;
    cout << runCustomerSimulation(1, "ABCBCA") << endl;
    cout << runCustomerSimulation(1, "ABCBCADEED") << endl;
    return 0;
}
