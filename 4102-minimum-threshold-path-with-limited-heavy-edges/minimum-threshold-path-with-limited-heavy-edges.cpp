class Solution {
public:
    bool bfs(vector<vector<vector<int>>>& adj, int& source, int& target, int k, int& thresh){
        deque<int> dq;
        int n = adj.size();
        vector<int> dist(n,INT_MAX);
        dist[source] = 0;
        dq.push_front(source);
        while(!dq.empty()){
            auto top = dq.front();
            dq.pop_front();
            int nde = top;
            for(auto nei: adj[nde]){
                int c = (nei[0]>thresh) ? 1 : 0;
                int nnode = nei[1];
                if(dist[nde]+c>=dist[nnode]) continue;
                dist[nnode] = dist[nde] + c;
                if(c==0) dq.push_front(nnode);
                else dq.push_back(nnode);
            }
        }
        return dist[target]<=k;
        
    }
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        vector<vector<vector<int>>> adj(n);
        int maxi = 0;
        for(auto ed: edges){
            adj[ed[0]].push_back({ed[2], ed[1]});
            adj[ed[1]].push_back({ed[2], ed[0]});
            maxi = max(maxi, ed[2]);
        }
        if(bfs(adj, source, target, k, maxi)==false) return -1;
        int l = 0;
        int r = maxi;
        while(l<=r){
            int m = (l + (r - l) / 2);
            bool check = bfs(adj, source, target, k, m);
            if(check) r = m-1;
            else l = m+1;
        }
        return l;

    }
};