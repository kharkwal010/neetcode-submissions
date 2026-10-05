class Solution {
public:
    long long inf = 1e11;
    vector<long long> weights(vector<vector<vector<int>>>& adj, int node, int n){
        vector<long long> dist(n, inf);
        dist[node] = 0;
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> minheap;
        minheap.push({0, node});
        while(!minheap.empty()){
            auto top = minheap.top();
            minheap.pop();
            long long w = top[0];
            int curr = top[1];
            if(dist[curr]<w) continue;
            for(auto nei: adj[curr]){
                if(dist[nei[1]]<=w + nei[0]) continue;
                dist[nei[1]] = w + nei[0];
                minheap.push({dist[nei[1]], nei[1]});
            }
        }
        return dist;
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<vector<int>>> adj(n);
        vector<vector<vector<int>>> radj(n);
        for(auto& ed: edges){
            adj[ed[0]].push_back({ed[2], ed[1]});
            radj[ed[1]].push_back({ed[2], ed[0]});
        }

        vector<long long> s1 = weights(adj, src1, n);
        vector<long long> s2 = weights(adj, src2, n);
        vector<long long> d = weights(radj, dest, n);
        long long ans = inf;
        for(int i=0; i<n; i++){
            ans = min(ans, s1[i]+s2[i]+d[i]);
        }
        return (ans==inf) ? -1 : ans;


        
    }
};