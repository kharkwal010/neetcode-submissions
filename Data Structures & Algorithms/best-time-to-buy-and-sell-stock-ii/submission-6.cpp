class Solution {
public:
    vector<vector<int>> memo;
    int profit(vector<int>& prices, int i, bool buy){
        if(i==prices.size()) return 0;
        if(memo[i][buy]!=INT_MAX) return memo[i][buy];
        int curr = (buy) ? -1 : 1;
        int leave = profit(prices, i+1, buy);
        int transact = curr * prices[i] + profit(prices, i+1, !buy);
        memo[i][buy] = max(leave, transact);
        return memo[i][buy];
    }
    int maxProfit(vector<int>& prices) {
        memo.resize(prices.size(), vector<int>(2, INT_MAX));
        return profit(prices, 0, true);
    }
};