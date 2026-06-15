class Solution {
public:
        unordered_map<int, int> memo;
    long dp(vector<int> coins, int amount){
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return INT_MAX;
        }
        if(memo.find(amount)!=memo.end()){
            return memo[amount];
        }
        long res = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            res = min(res, 1 + dp(coins, amount-coins[i]));
        }
        memo[amount]=res;
        return res;
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = dp(coins, amount);
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};
