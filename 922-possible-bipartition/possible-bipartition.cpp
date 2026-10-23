class Solution {
public:
    vector<int> col;
    bool bfs(vector<vector<int>>& adj, int nde){
        queue<int> q;
        q.push(nde);
        col[nde] = 1;
        while(!q.empty()){
            int sz = q.size();
            for(int k=0; k<sz; k++){
                int node = q.front();
                q.pop();
                for(int nei: adj[node]){
                    if(col[nei]==col[node]) return false;
                    if(col[nei]==2){
                        col[nei] = 1-col[node];
                        q.push(nei);
                    }
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        col.assign(n, 2);
        vector<vector<int>> adj(n);
        for(auto d: dislikes){
            adj[d[0]-1].push_back(d[1]-1);
            adj[d[1]-1].push_back(d[0]-1);
        }
        for(int i=0; i<n; i++){
            if(col[i]!=2) continue;
            bool res = bfs(adj, i);
            if(!res) return false;
        }
        return true;
    }
};