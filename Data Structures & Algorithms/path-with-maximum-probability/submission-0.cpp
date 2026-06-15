class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<double, int>>> adj(n);
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({succProb[i], edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i], edges[i][0]});
        }
        priority_queue<pair<double, int>> maxheap;
        maxheap.push({1.0, start_node});
        unordered_set<int> visited;
        while(!maxheap.empty()){
            auto top = maxheap.top();
            maxheap.pop();
            double prob = top.first;
            int node = top.second;
            visited.insert(node);
            if(node==end_node) return prob;
            for(auto nei: adj[node]){
                int n = nei.second;
                double p = nei.first;
                if(visited.count(n)) continue;
                maxheap.push({p*prob, n});
            }
        }
        return 0;
    }
};