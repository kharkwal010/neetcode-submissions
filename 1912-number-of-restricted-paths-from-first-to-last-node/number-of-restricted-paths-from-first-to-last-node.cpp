class Solution {
public:
    vector<int> memo;
    vector<int> dist;
    int mod = 1e9+7;
    int dfs(vector<vector<vector<int>>>& adj, int nde, int last){
        if(nde==last) return 1;
        if(memo[nde]!=-1) return memo[nde];
        long long ans = 0;
        for(auto& nei: adj[nde]){
            if(dist[nde]>dist[nei[1]]){
                ans = (ans + dfs(adj, nei[1], last))%mod;
            }
        }
        return memo[nde] = ans;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        
        dist.resize(n, INT_MAX);
        vector<vector<vector<int>>> adj(n);
        for(auto ed: edges){
            adj[ed[0]-1].push_back({ed[2], ed[1]-1});
            adj[ed[1]-1].push_back({ed[2], ed[0]-1});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        minheap.push({0, n-1});
        dist[n-1] = 0;
        while(!minheap.empty()){
            auto top = minheap.top();
            minheap.pop();
            int nde = top[1];
            int cost = top[0];
            if(dist[nde]<cost) continue;
            for(auto nei: adj[nde]){
                if(dist[nei[1]]<=cost+nei[0]) continue;
                dist[nei[1]]=cost+nei[0];
                minheap.push({dist[nei[1]], nei[1]});
            }
        }

        memo.resize(n, -1);
        return dfs(adj, 0, n-1);


    }
};