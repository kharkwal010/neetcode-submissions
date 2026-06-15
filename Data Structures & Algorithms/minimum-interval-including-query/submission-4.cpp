class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        unordered_map<int, int> match;
        sort(intervals.begin(), intervals.end());
        vector<int> q = queries;
        sort(q.begin(), q.end());
        int i=0;
        for(int term: q){
            while(i<intervals.size() && term>=intervals[i][0]){
                minheap.push({intervals[i][1]-intervals[i][0]+1, intervals[i][1]});
                i++;
            }
            while(!minheap.empty() && minheap.top()[1]<term){
                minheap.pop();
            }
            if(minheap.empty()) match[term] = -1;
            else match[term] = minheap.top()[0];            
        }
        vector<int> ans;
        for(auto& term: queries){
            ans.push_back(match[term]);
        }
        return ans;
    }
};
