// Find maximum height pyramid from the given array of objects
// https://www.geeksforgeeks.org/find-maximum-height-pyramid-from-the-given-array-of-objects/
// Given n objects, with each object has width wi. We need to arrange them in a pyramidal way such that : 
// Total width of ith is less than (i + 1)th.
// Total number of objects in the ith is less than (i + 1)th.
#include<bits/stdc++.h>
using namespace std;
  
// Returns maximum number of pyramidcal levels
// n boxes of given widths.
int maxLevel(int boxes[], int n)
{
    sort(boxes,boxes+n);
    int ans=1;
    int prev_count=1;
    int prev_width=boxes[0];
    int curr_count=0;
    int curr_width=0;
    for(int i=1;i<n;i++){
        curr_width+=boxes[i];
        curr_count++;
        if(curr_count>prev_count && curr_width>prev_width){
            prev_width=curr_width;
            prev_count=curr_count;

            curr_count=0;
            curr_width=0;
            ans++;
        }
    }
    return ans;
}
int main()
{
    int boxes[] = {10, 20, 30, 50, 60, 70};
    int n = sizeof(boxes)/sizeof(boxes[0]);
    cout << maxLevel(boxes, n) << endl;
    return 0;
}
