class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       vector<vector<int>> ans;
       int start = newInterval[0];
       int end = newInterval[1];
       int pos = 0;
       while(pos<intervals.size() && start>intervals[pos][0]){
            ans.push_back(intervals[pos]);
            pos++;
       }
       if(pos != 0 && ans[pos-1][1]>=start){
        start = ans[pos-1][0];
        end = max(end, ans[pos-1][1]);
        ans.pop_back();
       }

       while(pos<intervals.size() && end>=intervals[pos][0]){
        end = max(end, intervals[pos][1]);
         pos++;
       }
       ans.push_back({start, end});

        for(int i=pos; i<intervals.size(); i++){
            ans.push_back(intervals[i]);
        }
        return ans;

    }
};
