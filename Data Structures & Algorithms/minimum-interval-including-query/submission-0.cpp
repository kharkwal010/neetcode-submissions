class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> temp =queries;
        unordered_map<int, int> match;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        vector<int> ans;
        sort(queries.begin(), queries.end());
        sort(intervals.begin(), intervals.end());

        int i=0;
        int j=0;
        for(int i=0; i<queries.size(); i++){

            while(j<intervals.size() && queries[i]>=intervals[j][0]){
                int size = intervals[j][1]-intervals[j][0]+1;
                minheap.push({size, intervals[j][1]});
                j++;
            }
            while(!minheap.empty() && minheap.top()[1]<queries[i]){
                minheap.pop();
            }
            if(minheap.empty()){
                match[queries[i]]=-1;
            }
            else match[queries[i]]=minheap.top()[0];
        }

        for(int i=0; i<temp.size(); i++){
            ans.push_back(match[temp[i]]);
        }
        return ans;
    }
};
