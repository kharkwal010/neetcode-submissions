class Solution {
public:
    set<vector<int>> check;

    void backtrack(vector<int>nums, vector<vector<int>>& ans, vector<int>& comb, int target, int i){
        if(target==0){
            if(check.find(comb)==check.end()){
                ans.push_back(comb);
                check.insert(comb);
            }
            return;
        }
        if (target<0 || i>=nums.size()){
            return;
        }
        comb.push_back(nums[i]);
        backtrack(nums, ans, comb, target - nums[i], i+1);
        backtrack(nums, ans, comb, target - nums[i], i);
        comb.pop_back();
        backtrack(nums, ans, comb, target, i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        backtrack(nums, ans, comb, target, 0);
        return ans;
    }
};
