class Solution {
public:
    vector<vector<int>> adj;
    int count;
    long long sum(vector<int>& values, int nde, int parent, int k){
        long long val = values[nde];
        for(int nei: adj[nde]){
            if(nei==parent) continue;
            val += sum(values, nei, nde, k);
        }
        if(val%k==0) count++;
        return val;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        adj.resize(n);
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        count = 0;
        sum(values, 0, -1, k);
        return count;
    }
};