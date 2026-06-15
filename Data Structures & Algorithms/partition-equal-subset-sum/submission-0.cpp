class Solution {
public:
    void dfs(vector<int>& nums, int target, bool& res, vector<int>& comb, int i){
        if (target==0){
            res = true;
            return;
        }
        if (i==nums.size() || target<0){
            return;
        }
        comb.push_back(nums[i]);
        dfs (nums, target-nums[i], res, comb, i+1);
        comb.pop_back();
        dfs (nums, target, res, comb, i+1);
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum%2!=0){return false;}
        int ans = sum /2;
        bool res = false;
        vector<int> comb;
        dfs(nums, ans, res, comb, 0);
        return res;
        
    }
};
