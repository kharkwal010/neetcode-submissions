class Solution {
public:
    vector<vector<vector<int>>> adj;
    void dist(int n, vector<long long>& one, int src, vector<vector<vector<int>>>& adj){
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> minheap;
        minheap.push({0, src});
        one[src]=0;
        while(!minheap.empty()){
            auto top = minheap.top();
            minheap.pop();
            if(one[top[1]]<top[0]) continue;
            one[top[1]] = top[0];
            for(auto nei: adj[top[1]]){
                if (top[0] + nei[0] < one[nei[1]]) {
                    one[nei[1]] = top[0] + nei[0];
                    minheap.push({one[nei[1]], nei[1]});
                }
            }
        }
        return;
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<vector<int>>> adj(n);
        for(auto& ed: edges){
            adj[ed[0]].push_back({ed[2], ed[1]});
        }
        vector<vector<vector<int>>> radj(n);
        for(auto& ed: edges) radj[ed[1]].push_back({ed[2], ed[0]});
        long long INF = 1e18;
        vector<long long> one(n, INF);
        vector<long long> two(n, INF);
        dist(n, one, src1, adj);
        dist(n, two, src2, adj);
        vector<long long> destiny(n, INF);
        dist(n, destiny, dest, radj);
       long long ans = INF;
        for(int i=0; i<n; i++){
            if(one[i]==INF || two[i] == INF || destiny[i]==INF) continue;
            ans = min(ans, one[i] + two[i]+ destiny[i]);
        }
        if(ans==INF) return -1;
       
        return ans;


    }
};