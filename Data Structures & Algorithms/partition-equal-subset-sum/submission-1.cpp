class Solution {
public:
    vector<vector<int>> dp;
    bool dfs(vector<int>& nums, int target, bool& res, vector<int>& comb, int i){
        if (target==0){
            res = true;
            return true;
        }
        if (i==nums.size() || target<0){
            return false;
        }
        if (dp[i][target] != -1){
            return dp[i][target];
        }
        comb.push_back(nums[i]);
        bool push = dfs (nums, target-nums[i], res, comb, i+1);
        comb.pop_back();
        bool skip = dfs (nums, target, res, comb, i+1);
        return dp[i][target] = (push || skip);
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum%2!=0){return false;}
        int ans = sum /2;
        bool res = false;
        vector<int> comb;
        dp.assign(nums.size(), vector<int>(ans + 1, -1));
        dfs(nums, ans, res, comb, 0);
        return res;
        
    }
};
