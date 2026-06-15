class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start = newInterval[0];
        int end = newInterval[1];
        int n = intervals.size();
        vector<vector<int>> ans;
        int i=0;
        while(i<n && start>intervals[i][1]){
            ans.push_back(intervals[i]);
            i++;
        }
        if(i<n){
            start = min(start, intervals[i][0]);
        }
        while(i<n && end>=intervals[i][0]){
            end = max(end, intervals[i][1]);
            i++;
        }
        ans.push_back({start, end});
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
