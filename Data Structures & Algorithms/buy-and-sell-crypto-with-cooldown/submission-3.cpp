class Solution {
public:
    // here a simple thing is needed to be noted, if you buy at a level
    //  and sell and then again buy it, then in that condition the profit is
    // always greater or equal to the condition that you buy at that level for the
    // first time if you are using max value to store in dp for the first time
    
    unordered_map<string, int> memo;
    int dfs(vector<int> prices, int i, int sum, bool buy){
        if(i>=prices.size()){
            return sum;
        }
        string key = to_string(sum)+to_string(buy)+"+"+to_string(i);
        if(memo.find(key)!=memo.end()){
            return memo[key];
        }
        int purchase;
        if(buy){
            purchase =dfs(prices, i+1, sum-prices[i], false);
        }
        else{
            purchase = dfs(prices, i+2, sum + prices[i], true);
        }
        int leave = dfs(prices, i+1, sum, buy);
        memo[key]= max(leave, purchase);
        return memo[key];
        }
        
    int maxProfit(vector<int>& prices) {
        return dfs(prices, 0, 0, true);

    }
};
