class Solution {
public:
    unordered_map<string, int> memo;
    int dp(int amount, vector<int>& coins, int i){
        if(amount==0) return 1;
        if(amount<0) return 0;
        string key = to_string(amount) + "," + to_string(i);
        if(memo.find(key)!=memo.end()) return memo[key];
        int ans = 0;
        for(int j=i; j<coins.size(); j++){
            ans = ans + dp(amount-coins[j], coins, j);
        }
        memo[key] = ans;
        return ans;
    }


    int change(int amount, vector<int>& coins) {
        return dp(amount, coins, 0);
    }
};
