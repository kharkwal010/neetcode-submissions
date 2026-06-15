class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        if (intervals.size()==0){
            res.push_back(newInterval);
            return res;
        }
        int target = newInterval[0];
        int pos=intervals.size();
        for(int i=0; i<intervals.size(); i++){
            if (target<intervals[i][0]){
                pos = i;
                break;
            }           
                res.push_back(intervals[i]);
        }
        while(pos<=intervals.size()){
            if(res.size()==0){
                res.push_back(newInterval);
            }
            else if (res.back()[1]>=newInterval[0]){
                res.back()[1]= max(res.back()[1], newInterval[1]);
            }
            else{
                res.push_back(newInterval);
            }
            if(pos<intervals.size()){
               newInterval = intervals[pos];
            }
            pos++;
        }  
        return res;            
     
    }
};
