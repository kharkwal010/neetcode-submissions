class Solution {
public:
    long long total;
    long long cost(vector<vector<int>>& adj, int seats, int curr, int parent){
        long long men = 1;
        for(int nei: adj[curr]){
            if(nei==parent) continue;
            men += cost(adj, seats, nei, curr);
        }
        if(curr!=0) total += ceil((double)men/seats);
        return men;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        total = 0;
        int n = roads.size()+1;
        vector<vector<int>> adj(n);
        for(auto e: roads){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        cost(adj, seats, 0, -1);
        return total;

    }
};