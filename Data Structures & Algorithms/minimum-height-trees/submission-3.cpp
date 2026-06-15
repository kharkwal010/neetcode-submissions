class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }

        queue<int> q;

        // push all leaves
        for(int i = 0; i < n; i++){
            if(indegree[i] == 1) q.push(i);
        }

        int remaining = n;

        while(remaining > 2){
            int sz = q.size();
            remaining -= sz;

            while(sz--){
                int node = q.front(); q.pop();

                for(auto nei : adj[node]){
                    indegree[nei]--;
                    if(indegree[nei] == 1){
                        q.push(nei);
                    }
                }
            }
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};