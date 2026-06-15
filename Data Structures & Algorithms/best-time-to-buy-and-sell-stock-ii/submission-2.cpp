class Solution {
public:
    unordered_map<string, int> memo;
    // if i am in a state of total 12 and already calc for 15 at that level than this is useless
    // thus this logic is not useful in many of the cases the tle one 
     
    int dp(vector<int> prices, int i, bool sell){
        if(i==prices.size()){            
            return 0;
        }
        string key =  to_string(sell) + to_string(i);
        if(memo.find(key)!=memo.end()){
            return memo[key];
        }
        // leave;
        int leave = dp(prices, i+1, sell);

        // pick;
        int pick;
        if(sell){
            sell= false;
            pick = dp(prices, i+1, sell)+prices[i];
        }
        else{
            sell = true;
            pick = dp(prices, i+1, sell)-prices[i];
        }
        memo[key]=max(pick, leave);
        return memo[key];
    }
    int maxProfit(vector<int>& prices) {
        return dp(prices, 0, false);
    }
};