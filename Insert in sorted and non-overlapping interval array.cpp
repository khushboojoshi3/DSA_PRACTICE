// Insert in sorted and non-overlapping interval array
// Input: Set : [1, 3], [6, 9]
//         New Interval : [2, 5] 
// Output: [1, 5], [6, 9]
// The correct position to insert new interval 
// [2, 5] is between the two given intervals. 
// The resulting set would have been 
// [1, 3], [2, 5], [6, 9], but the intervals 
// [1, 3], [2, 5] are overlapping. So, they are 
// merged together in one interval [1, 5]. 
// https://leetcode.com/problems/insert-interval/submissions/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        for(int i=0;i<intervals.size();i++){
            // case1
            //1---2 ->interval[i]
            //3--5  ->newInterval
            if(intervals[i][1]<newInterval[0]){
                res.push_back(intervals[i]);
            }
            
//             case2
            // 2---4--->new Interval
            // 5---6--->interval[i]
            else if(intervals[i][0]>newInterval[1]){
                 res.push_back(newInterval);
                newInterval=intervals[i];
            }
            //case3
            
            // 1------3----------6-----9 //intervals arrray
               // 2----------------7 //newInterval
            else if(intervals[i][1]>=newInterval[0] || intervals[i][0]<=newInterval[1]){
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        res.push_back(newInterval); 
        return res;
    }
};
