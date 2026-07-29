class Solution {
public:
    bool bfs(vector<vector<int>>& adj, vector<int>& visited, int curr){
        visited[curr] = 0;
        queue<int> q;
        q.push(curr);
        bool col = true;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                int nde = q.front();
                q.pop();
                for(int nei: adj[nde]){
                    if(visited[nei]==2){
                        visited[nei] = col;
                        q.push(nei);
                    }
                    else if(visited[nei]!=col) return false;
                }
            }
            col = !col;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n);
        for(auto ele: dislikes){
            adj[ele[0]-1].push_back(ele[1]-1);
            adj[ele[1]-1].push_back(ele[0]-1);
        }
        vector<int> visited(n, 2);
        for(int i=0; i<n; i++){
            if(visited[i]==2){
                if(!(bfs(adj, visited, i))){
                    // for(int i=0; i<n; i++) cout<<visited[i]<<" ";
                    return false;
                }
            }
        }
        return true;
    }
};