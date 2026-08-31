class Solution {
public:
    vector<vector<vector<int>>> adj;
    bool bfs(int& n, int& src, int& tar, int k, int thresh){
        vector<vector<bool>> visited(n, vector<bool>(k+1, false));
        queue<pair<int, int>> q;
        q.push({src, k});
        visited[src][k] = true;
        while(!q.empty()){
            int sz = q.size();
            for(int j=0; j<sz; j++){
                auto top = q.front();
                int curr = top.first;
                int chance = top.second;
                q.pop();
                for(auto nei: adj[curr]){
                    bool heavy = (nei[0]>thresh);
                    if((heavy && chance==0) || visited[nei[1]][chance-heavy]) continue;
                    if(chance<k && visited[nei[1]][chance+1]) continue;
                    visited[nei[1]][chance-heavy] = true;
                    if(nei[1]==tar) return true;
                    q.push({nei[1], chance-heavy});
                }
            }
        }
        return false;
    }
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        adj.resize(n);
        int l = 0;
        int r = 0;
        if(source==target) return 0;
        for(auto& ed: edges){
            adj[ed[0]].push_back({ed[2], ed[1]});
            adj[ed[1]].push_back({ed[2], ed[0]});
            r = max(r, ed[2]);
        }
        int ans = r;
        if(!bfs(n, source, target, k, ans)) return -1;
        while(l<=r){
            int m = l + (r-l) / 2;
            if(bfs(n, source, target, k, m)){
                ans = m;
                r = m-1;
            }
            else l = m+1;
        }
        return ans;
        

    }
};