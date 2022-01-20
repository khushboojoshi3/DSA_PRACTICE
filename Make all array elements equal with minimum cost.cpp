// Make all array elements equal with minimum cost
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

// https://www.youtube.com/watch?v=Wo168YDPwzk

// Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

// In one move, you can increment or decrement an element of the array by 1.

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        int i=0;
        int j=n-1;
        while(i<=j){
            ans+=abs(nums[j]-nums[i]);
            i++;
            j--;
        }
        return ans;
    }
};
