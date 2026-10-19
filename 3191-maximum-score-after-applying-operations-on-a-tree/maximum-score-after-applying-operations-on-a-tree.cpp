class Solution {
public:
    long long path(vector<vector<int>>& adj, vector<int>& values, int node, int parent){
        long long ans = values[node];
        long long nval = 0;
        for(int nei: adj[node]){
            if(nei==parent) continue;
            nval += path(adj, values, nei, node);
        }
        if(nval==0) nval = LLONG_MAX;
        return min(ans, nval);

    }
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<int>> adj(n);
        for(auto& ed: edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        long long ignore =  path(adj, values, 0, -1);
        long long sum = 0;
        for(int val: values) sum += val;
        return sum - ignore;

    }
};