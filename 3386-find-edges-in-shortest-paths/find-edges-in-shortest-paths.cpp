class Solution {
public:
    vector<vector<vector<int>>> adj;
    long long inf = 1e10;
    vector<long long> paths(int start, int n){
        vector<long long> path(n, inf);
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> minheap;
        minheap.push({0, start});
        path[start] = 0;
        while(!minheap.empty()){
            auto top = minheap.top();
            minheap.pop();
            int nde = top[1];
            long long cost = top[0];
            if(path[nde]<cost) continue;
            for(auto nei: adj[nde]){
                long long c = nei[0] + cost;
                if(path[nei[1]]<=c) continue;
                path[nei[1]] = c;
                minheap.push({c, nei[1]});
            }
        }
        return path;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto e: edges){
            adj[e[0]].push_back({e[2], e[1]});
            adj[e[1]].push_back({e[2], e[0]});
        }
        vector<long long> path = paths(0, n);
        vector<long long> last = paths(n-1, n);
        long long small = last[0];
        vector<bool> ans(edges.size(), false);
        for(int i=0; i<edges.size(); i++){
            auto e = edges[i];
            if(path[e[0]]+last[e[0]]>small) continue;
            if(path[e[1]] + last[e[1]]> small) continue;
            long long shortest = path[e[0]] + e[2];
            if(shortest==path[e[1]]) ans[i] = true;
            else{
                shortest = path[e[1]] + e[2];
                if(shortest== path[e[0]]) ans[i] = true;
            }
            // cout<<path[e[0]] <<" "<<path[e[1]]<<" "<<endl;
        }
        return ans;

    }
};