class Solution {
public:    
    vector<int> visited;
    void bfs(vector<vector<int>>& adj, int curr){
        queue<int> q;
        q.push(curr);
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(int nei: adj[top]){
                if(visited[nei]) continue;
                visited[nei] = true;
                q.push(nei);
            }
        }
        return;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        visited.resize(n, false);
        vector<vector<int>> adj(n);
        for(auto ed: connections){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        int count = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                visited[i] = true;
                bfs(adj, i);
                count++;
            }
        }
        return count-1;
    }
};