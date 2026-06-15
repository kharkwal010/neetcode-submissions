class Solution {
public:
    unordered_map<string, int> memo;
    int dfs(int amount, vector<int> coins, int layer){
        if(amount==0){
            return 1;
        }
        else if(amount<0){
            return 0;
        }
        string key = to_string(amount)+"+"+to_string(layer);
        if(memo.find(key)!=memo.end()){
            return memo[key];
        }
        int ans = 0;
        for(int i = layer; i<coins.size(); i++){
            ans = ans + dfs(amount-coins[i], coins, i);
        }
        memo[key]= ans;
        return ans;

    }

    int change(int amount, vector<int>& coins) {
        
        // memo = vector<vector<int>>(coins.size()+1, vector<int>(amount + 1, -1));
        return dfs(amount, coins, 0);
    }
};
