class Solution {
public:
    vector<int> visited;
    void dfs(vector<vector<int>>& adj, int i){
        // cout<<i <<" "<<adj[i].size()<<endl;
        for(int nei: adj[i]){
            if(visited[nei]) continue;
            visited[nei] = true;
            dfs(adj, nei);
        }
        return;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int con = connections.size();
        if(con<n-1) return -1;
        vector<vector<int>> adj(n);
        for(auto ele: connections){
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
        }
        visited.resize(n, false);
        int count = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                // cout<<i<<endl;
                visited[i] = true;
                dfs(adj, i);
                count++;
            }
        }
        return count-1;
    }
};