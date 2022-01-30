// Find minimum time to finish all jobs with given constraints
// https://www.geeksforgeeks.org/find-minimum-time-to-finish-all-jobs-with-given-constraints/
// K:     Number of assignees available.
// T:     Time taken by an assignee to finish one unit 
//        of job
// job[]: An array that represents time requirements of 
//        different jobs.

// Input:  k = 2, T = 5, job[] = {4, 5, 10}
// Output: 50
// The minimum time required to finish all the jobs is 50.
// There are 2 assignees available. We get this time by 
// assigning {4, 5} to first assignee and {10} to second 
// assignee.

// Input:  k = 4, T = 5, job[] = {10, 7, 8, 12, 6, 8}
// Output: 75
// We get this time by assigning {10} {7, 8} {12} and {6, 8}

#include<bits/stdc++.h>
using namespace std;
bool isPossible(int time,int K,int job[],int n){
    int curr_time=0;
    int cnt=1;
    for(int i=0;i<n;i++){
        if(job[i]>time) return false;
        curr_time+=job[i];
        if(curr_time>time){
            curr_time=job[i];
            cnt++;
        }
        if(cnt>K) return false;
    }
    return true;
}
int findMinTime(int K,int T,int job[],int n){
    int start=0;
    int end=0;
    for(int i=0;i<n;i++){
        end+=job[i];
    }
    int ans=end;
    while(start<=end){
        int mid=(start+end)/2;
        if(isPossible(mid,K,job,n)){
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans*T;
}
int main() {
    // int job[] =  {10, 7, 8, 12, 6, 8};
    // int n = sizeof(job)/sizeof(job[0]);
    // int k = 4, T = 5;
    // cout << findMinTime(k, T, job, n) << endl;
    int job[] =  {4,5,10};
    int n = sizeof(job)/sizeof(job[0]);
    int k = 2, T = 5;
    cout << findMinTime(k, T, job, n) << endl;
    return 0;
}
