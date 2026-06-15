class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      vector<vector<int>> ans;
      int start = newInterval[0];
      int end = newInterval[1];
      int i=0;
      while(i<intervals.size() && intervals[i][1]<start){
        ans.push_back(intervals[i]);
        i++;
      }
      if(i<intervals.size()) start = min(start, intervals[i][0]);
      while(i<intervals.size() && intervals[i][0]<=end){
        end = max(end, intervals[i][1]);
        i++;
      }
      ans.push_back({start, end});
      while(i<intervals.size()){
        ans.push_back({intervals[i]});
        i++;
      }
      return ans;
    }
};
