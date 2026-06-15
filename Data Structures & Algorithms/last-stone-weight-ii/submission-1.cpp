class Solution {
public:
    unordered_map<string, int> memo;
    int dp(vector<int> stones, int i, int sum, double target){
        if(sum>=target){
            return 2*(sum - target);
        }
        if(i>=stones.size()){
            return INT_MAX;
        }
        string key = to_string(i)+"+"+to_string(sum);
        if(memo.find(key)!=memo.end()){
            return memo[key];
        }
        int pick = dp(stones, i+1, sum + stones[i], target);
        int leave = dp(stones, i+1, sum, target);
        memo[key]=min(pick, leave);
        return memo[key];
    }
    int lastStoneWeightII(vector<int>& stones) {
        double target = 0;
        for(int i=0; i<stones.size(); i++){
            target = target + stones[i];
        }
        target = target / 2;
        return dp(stones, 0, 0, target); 
    }
};