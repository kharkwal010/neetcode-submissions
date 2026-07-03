class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> indeg(n, 0);
        vector<vector<int>> adj(n);
        for(auto ele: relations){
            adj[ele[0]-1].push_back(ele[1]-1);
            indeg[ele[1]-1]++;
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        for(int i=0; i<n; i++){
            if(indeg[i]==0) minheap.push({time[i], i});
        }
        int t = 0;
        while(!minheap.empty()){
            auto top = minheap.top();
            minheap.pop();
            t = top[0];
            for(int nei: adj[top[1]]){
                indeg[nei]--;
                if(indeg[nei]==0) minheap.push({t + time[nei], nei});
            }
        }
        return t;
    }
};