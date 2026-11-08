class Solution {
public:
    vector<vector<long long>> dp;
    vector<int> sz;
    long long inf = 1e15;

    void costing(vector<vector<int>>& adj, string& col, int curr, int parent){
        sz[curr] = 1;
        for(int nei: adj[curr]){
            if(nei==parent) continue;
            costing(adj, col, nei, curr);
            sz[curr] += sz[nei];
        }

        long long red = (col[curr]=='R') ? 0 : sz[curr];
        long long blue = (col[curr]=='B') ? 0 : sz[curr];
        
        dp[curr][0] = blue;
        dp[curr][1] = red;
        dp[curr][2] = inf;

        for(int nei: adj[curr]){
            if(nei==parent) continue;
            dp[curr][0] += dp[nei][0];
            dp[curr][1] += min(dp[nei][1], dp[nei][0]);
        }

        
        for(int nei : adj[curr]){
            if(nei==parent) continue;
            long long cost = dp[curr][0];
            cost -= dp[nei][0];
            cost += min(dp[nei][1], dp[nei][2]);
            dp[curr][2] = min(dp[curr][2], cost);
        }
        return;
    }

    long long minCost(int n, string colors, vector<vector<int>>& edges) {
        dp.assign(n, vector<long long>(3, inf));
        sz.resize(n);
        vector<vector<int>> adj(n);
        for(auto& ed: edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        costing(adj, colors, 0, -1);
        // cout<<dp[0][0]<<" "<< dp[0][1]<<" "<< dp[0][2]<<endl;
        return min({dp[0][0], dp[0][1], dp[0][2]});

    }
};









// ans can be achieved by three ways:
/*
1. making all the nodes blue
2. making the current node the part of a large red connected component.
3. making everything blue but a red connected component down somewhere. (my current node too will be blue here)
just make dp for these three states...
*/