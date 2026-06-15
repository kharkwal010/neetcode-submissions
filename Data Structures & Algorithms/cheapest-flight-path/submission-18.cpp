class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> cost(n, INT_MAX);
        cost[src] = 0;
        for(int i=0; i<k+1; i++){
            vector<int> layer = cost;
            for(auto f: flights){
                if(cost[f[0]]!=INT_MAX) layer[f[1]] = min(layer[f[1]], cost[f[0]]+f[2]);
            }
            cost = layer;
        }
        return (cost[dst]!=INT_MAX) ? cost[dst] : -1;
    }
};
