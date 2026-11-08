class Solution {
public:
    vector<vector<int>> adj;
    vector<int> seen;
    void dfs(int node, string& s, vector<int>& parent){
        int j = s[node] - 'a';
        if(seen[j]!=-1){
            parent[node] = seen[j];
        }
        int prev = seen[j];
        seen[j] = node;
        for(int nei: adj[node]){
            dfs(nei, s, parent);
        }
        seen[j] = prev;
        return;        
    }
    vector<int> res;
    void sizes(int node){
        res[node] = 1;
        for(int nei: adj[node]){
            sizes(nei);
            res[node] += res[nei];
        }
        return;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = s.size();
        adj.resize(n);
        seen.assign(26, -1);
        for(int i=1; i<n; i++){
            adj[parent[i]].push_back(i);
        }
        dfs(0, s, parent);
        adj.assign(n, {});
        for(int i=1; i<n; i++){
            adj[parent[i]].push_back(i);
        }
        res.resize(n);
        sizes(0);
        return res;
    }
};