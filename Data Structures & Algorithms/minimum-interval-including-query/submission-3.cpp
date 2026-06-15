class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        sort(intervals.begin(), intervals.end());
        vector<int> quer = queries;
        sort(quer.begin(), quer.end());
        unordered_map<int, int> memo;

        int i=0;
        for(int q: quer){
            while(i<intervals.size() && intervals[i][0]<=q){
                int l = intervals[i][0];
                int r = intervals[i][1];
                minheap.push({r-l+1, l, r});
                i++;
            }
            while(!minheap.empty() && minheap.top()[2]<q){
                minheap.pop();
            }
            if(minheap.empty()) memo[q] = -1;
            else memo[q] = minheap.top()[0];
        }
        vector<int> ans(queries.size(),0);
        for(int i=0; i<queries.size(); i++){
            ans[i] = memo[queries[i]];
        }
        return ans;
    }
};
