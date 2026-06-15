class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<int> indeg(n, 0);
        vector<vector<int>> adj(n);
        for(auto ed: edges){
            indeg[ed[0]]++;
            indeg[ed[1]]++;
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        int count = 0;
        vector<bool> visited(n, false);
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indeg[i]==1){
                q.push(i);
                visited[i] = true;
                count++;
            }
        }
        while(count<n){
            int size = q.size();
            for(int i=0; i<size; i++){
                int top = q.front();
                q.pop();
                for(int nei: adj[top]){
                    if(visited[nei]) continue;
                    indeg[nei]--;
                    if(indeg[nei]==1){
                        q.push(nei);
                        visited[nei] = true;
                        count++;
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