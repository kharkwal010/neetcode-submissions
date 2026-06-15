class Solution {
public:
    void dfs(vector<int>& nums, vector<int> ans, vector<vector<int>>& result, int i){
        if(i==nums.size()){
            result.push_back(ans);
            return;
        }
        dfs(nums, ans, result, i+1);
        ans.push_back(nums[i]);
        dfs(nums, ans, result, i+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(nums, {}, ans, 0);
        return ans;

    }
};
