class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start = newInterval[0];
        int end = newInterval[1];
        int pos = 0;
        vector<vector<int>> ans;

        // add non-overlapping before
        while(pos < intervals.size() && intervals[pos][1] < start){
            ans.push_back(intervals[pos]);
            pos++;
        }

        // merge overlapping
        while(pos < intervals.size() && intervals[pos][0] <= end){
            start = min(start, intervals[pos][0]);
            end = max(end, intervals[pos][1]);
            pos++;
        }
        ans.push_back({start, end});

        // add rest
        while(pos < intervals.size()){
            ans.push_back(intervals[pos]);
            pos++;
        }

        return ans;
    }
};
