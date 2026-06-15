class Solution {
public:
    unordered_map<int, long> memo;
    long dp(vector<int>& coins, int amount){
        if(amount==0){
            return 0;
        }
        else if(amount<0){
            return INT_MAX;
        }
        if(memo.find(amount)!=memo.end()){
            return memo[amount];
        }
        long sum = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            sum = min(sum, 1+dp(coins, amount-coins[i]));
        }
        memo[amount]=sum;
        return memo[amount];

    }
    
    int coinChange(vector<int>& coins, int amount) {   
        long ans = dp(coins, amount);  
        if(ans>=INT_MAX){
            return -1;
        } 
       return ans;

    }
};
