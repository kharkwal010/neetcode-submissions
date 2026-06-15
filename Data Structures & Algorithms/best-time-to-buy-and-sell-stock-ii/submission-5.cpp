class Solution {
public:
    unordered_map<string , int> memo;
    int profit(vector<int>& prices, bool buy, int i){
        if(i==prices.size()) return 0;
        string key = to_string(i) + "," + to_string(buy);
        if(memo.find(key)!=memo.end()) return memo[key];
        int val = (buy) ? -1 : 1;
        int leave = profit(prices, buy, i+1);
        int trans = profit(prices, !buy, i+1)+val*prices[i];
        memo[key] = max(leave, trans);
        return memo[key];
    }
    int maxProfit(vector<int>& prices) {
        return profit(prices, true , 0);
    }
};