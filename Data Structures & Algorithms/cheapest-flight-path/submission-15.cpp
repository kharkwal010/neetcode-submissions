class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> cost(n, INT_MAX);
        cost[src] = 0;
        while(k>=0){
            vector<int> temp = cost;
            for(auto ele: flights){
                if(cost[ele[0]]!=INT_MAX){
                    temp[ele[1]] = min(temp[ele[1]], cost[ele[0]] + ele[2]);
                }
            }
            cost = temp;
            k--;
        }
        if(cost[dst]==INT_MAX) return -1;
        return cost[dst];
    }
};
