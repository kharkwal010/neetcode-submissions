class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto ele: flights){
            adj[ele[0]].push_back({ele[2], ele[1]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        minheap.push({0, src, k+1});
        while(!minheap.empty()){
            auto top = minheap.top();
            minheap.pop();
            if(top[1]==dst) return top[0];
            if(top[2]==0) continue;
            for(auto nei: adj[top[1]]){
                int cost = nei.first;
                int node = nei.second;
                minheap.push({top[0]+cost, node, top[2]-1});
            }
        }
        return -1;
    }
};