class Solution {
public:
    vector<bool> path;
    vector<bool> visited;
    vector<vector<int>> memo;
    void dfs(vector<vector<int>>& adj, int curr, string& col, bool& cycle){
        if(cycle) return;
        if(adj[curr].size()==0){
            memo[curr][col[curr]-'a'] = 1;
            return;
        }
        if(visited[curr]) return;
        visited[curr] = true;
        path[curr] = true;

        for(int nei: adj[curr]){
            if(path[nei]){
                cycle = true;
                return;
            }
            dfs(adj, nei, col, cycle);
            for(int i=0; i<26; i++){
                if(i==col[curr]-'a') memo[curr][i] = max(memo[curr][i], 1 + memo[nei][i]);
                else memo[curr][i] = max(memo[curr][i], memo[nei][i]);
            }

        }
        path[curr] = false;

    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        path.assign(n, false);
        visited.assign(n, false);
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto& e: edges){
            if(e[0]==e[1]) return -1;
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        memo.resize(n, vector<int>(26, 0));
        int ans = -1;
        for(int i=0; i<n; i++){
            bool cycle = false;
            dfs(adj, i, colors, cycle);
            if(cycle) return -1;
            for(int j=0; j<26; j++){
                ans = max(ans, memo[i][j]);
            }
        }
        return ans;      
        
    }
};