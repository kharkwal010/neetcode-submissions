class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> ans = queries;
        unordered_map<int, int> val;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;

        sort(queries.begin(), queries.end());
        sort(intervals.begin(), intervals.end());

        int i = 0;
        for(int q : queries){
            while(i<intervals.size() && q>=intervals[i][0]){
                int s = intervals[i][0];
                int e = intervals[i][1];
                minheap.push({e-s+1, s, e});
                i++;
            }
            while(!minheap.empty() && minheap.top()[2]<q){
                minheap.pop();
            }
            if(!minheap.empty()) val[q] = minheap.top()[0];
        }
        for(int n=0; n<ans.size(); n++){
            if(val.find(ans[n])!=val.end()) ans[n] = val[ans[n]];
            else ans[n] = -1;
        }
        return ans;
    }
};
