class Solution {
public:
unordered_map<int, int> memo;
    long dp(vector<int> coins, int amount){
        if(amount == 0){
            return 0;
        }
        if(amount< 0){
            return INT_MAX;
        }
        if(memo.find(amount)!=memo.end()){
            return memo[amount];
        }
        long ans= INT_MAX;
        for(int i=0; i<coins.size(); i++){
            ans = min(ans, 1+ dp(coins, amount-coins[i]));
        }
        memo[amount] = ans;
        return ans;

    }
     
    int coinChange(vector<int>& coins, int amount) {
        int ans = dp(coins, amount);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
       
    }
};
