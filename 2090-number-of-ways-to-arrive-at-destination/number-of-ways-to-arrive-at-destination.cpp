class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // here i need {cost, node, freq}; and need a freq array too;
        int mod = 1e9+7;
        vector<vector<vector<int>>> adj(n);
        for(auto ele: roads){
            adj[ele[0]].push_back({ele[2], ele[1]});
            adj[ele[1]].push_back({ele[2], ele[0]});
        }
        vector<long long> cost(n, LLONG_MAX);
        vector<long long> freq(n, 0);
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> minheap;
        cost[0] = 0;
        freq[0] = 1;
        minheap.push({0,0,0});
        while(!minheap.empty()){
            auto top = minheap.top();
            minheap.pop();
            long long c = top[0];
            int node = top[1];            
            if(cost[node]<c) continue;
            for(auto nei: adj[node]){
                int nnode = nei[1];
                if(cost[nnode]>c+nei[0]){
                    cost[nnode] = c + nei[0];
                    freq[nnode] = freq[node];
                    minheap.push({nei[0]+c, nnode});
                }                
                else if(cost[nnode]==nei[0]+c){
                    freq[nnode] = (freq[nnode] + freq[node])%mod;
                }
            }

        }
        return freq[n-1];
    }
};