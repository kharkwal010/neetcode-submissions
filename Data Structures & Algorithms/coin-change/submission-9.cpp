class Solution {
public:
    unordered_map<int, long> memo;
    long dp(int amount, vector<int> coins){
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return INT_MAX;
        }
        if(memo.find(amount)!=memo.end()){
            return memo[amount];
        }
        long ans = INT_MAX;
        for(int coin: coins){
                ans = min(1+ dp(amount-coin, coins), ans);            
        }
        memo[amount]=ans;
        return memo[amount];
        
    }

    int coinChange(vector<int>& coins, int amount) {        
       int ans  = dp(amount, coins);
       if(ans==INT_MAX){
        return -1;
       }
       return ans;
    }
};
