class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int end = 0;
        int count = 0;
        int p_start = -1;
        for(auto ele: intervals){
            if(ele[1]<=end || ele[0]==p_start) count++;
            end = max(end, ele[1]);
            p_start = ele[0];
        }
        return intervals.size() - count;
    }
};