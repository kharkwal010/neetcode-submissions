class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<vector<int>>> adj;
        for(auto ele: times){
            adj[ele[0]].push_back({ele[2], ele[1]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        unordered_set<int> visited;
        int count = 0;
        minheap.push({0, k});
        int node, price;
        while(!minheap.empty()){
            auto top = minheap.top();
            minheap.pop();
            node = top[1];
            if(visited.count(node)) continue;
            visited.insert(node);
            count++;
            price = top[0];
            if (count==n) return price;
            for(auto nei: adj[node]){
                if(!visited.count(nei[1])){
                    minheap.push({price+nei[0], nei[1]});
                }
            }            
        }
        return -1;
    }
};
