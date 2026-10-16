class Solution {
public:
    vector<int> suspicious;
    bool bfs(vector<int>& visited, int node, vector<vector<int>>& adj){
        queue<int> q;
        q.push(node);
        visited[node] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int nei: adj[curr]){
                if(suspicious[nei]){
                    return true;
                }
                if(visited[nei]) continue;
                visited[nei] = true;
                q.push(nei);
            }
        }
        return false;
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto& e: invocations) adj[e[0]].push_back(e[1]);
        suspicious.assign(n, false);
        queue<int> q;
        q.push(k);
        suspicious[k] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int nei: adj[curr]){
                if(suspicious[nei]) continue;
                suspicious[nei] = true;
                q.push(nei);
            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(!suspicious[i]) ans.push_back(i);
        }
        bool check = false;

        vector<int> visited(n, false);
        for(int i=0; i<n; i++){
            if(suspicious[i] || visited[i]) continue;
            check = bfs(visited, i, adj);
            if(check) break;
        }
        if(!check) return ans;
        for(int i=0; i<n; i++){
            if(suspicious[i]) ans.push_back(i);
        }
        return ans;
        
    }
};