class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& hasApple){
        int ans = 0;
        for(int nei: adj[node]){
            int child =0;
            if(nei==parent) continue;
            child = dfs(nei, node, adj, hasApple);
            if(hasApple[nei] || child>0) ans +=  2 + child;
        }
        
        return ans;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto& ed: edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        return dfs(0, -1, adj, hasApple);
        
    }
};