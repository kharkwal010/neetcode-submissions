class Solution {
public:
    vector<int> sz;
    vector<int> ans;
    int val(vector<vector<int>>& adj, int curr, int parent){
        sz[curr] = 1;
        for(int nei: adj[curr]){
            if(nei==parent) continue;
            sz[nei] = val(adj, nei, curr);
            sz[curr] += sz[nei];
        }
        if(curr!=0) ans[0] += sz[curr];
        return sz[curr];
    }

    void dfs(vector<vector<int>>& adj, int curr, int parent, int& n){
        if(parent!=-1){
            ans[curr] = ans[parent] + n - 2*sz[curr];
        }
        for(int nei: adj[curr]){
            if(nei==parent) continue;
            dfs(adj, nei, curr, n);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        sz.resize(n, 0);
        vector<vector<int>> adj(n);
        for(auto& ed: edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        ans.resize(n,0);
        val(adj, 0, -1);
        dfs(adj, 0, -1, n);
        return ans;
        
    }
};