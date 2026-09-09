class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);
        for(auto nei: edges){
            adj[nei[0]].push_back(nei[1]);
            adj[nei[1]].push_back(nei[0]);
            indeg[nei[0]]++;
            indeg[nei[1]]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            // cout<<i<<" "<<indeg[i]<<endl;
            if(indeg[i]==1) q.push(i);
        }
        while(!q.empty()){
            if(n<=2) break;
            int sz = q.size();
            // cout<<sz<<endl;
            for(int i=0; i<sz; i++){
                int curr = q.front();
                // cout<<curr<<endl;
                q.pop();
                n--;
                for(int nei: adj[curr]){
                    indeg[nei]--;
                    if(indeg[nei]==1) q.push(nei);
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