class Solution {
public:   
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int curr){
        for(int nei: adj[curr]){
            if(visited[nei]) continue;
            visited[nei] = true;
            dfs(adj, visited, nei);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);
        for(auto& c: connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        if(connections.size()+1<n) return -1;
        int count = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                visited[i] = true;
                count++;
                dfs(adj, visited, i);
            }
        }
        return count-1;
    }
};