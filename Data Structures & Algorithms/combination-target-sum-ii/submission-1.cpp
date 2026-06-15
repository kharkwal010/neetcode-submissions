class Solution {
public:
    set <vector<int>> check;
    void backtrack(vector<int> nums, int target, vector<int>& comb, vector<vector<int>>& ans, int i){
        if (target==0){
            vector<int> temp = comb;
            sort(temp.begin(), temp.end());
            
            if (check.find(temp)==check.end()){
                check.insert(temp);
                ans.push_back(temp);
                return;
            }
        }
        if (target<0 || i==nums.size()){
            return;
        }
        comb.push_back(nums[i]);
        backtrack(nums, target - nums[i], comb, ans, i+1);
        comb.pop_back();
        backtrack(nums, target, comb, ans, i+1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int>> ans;
        backtrack(candidates, target, comb, ans, 0);
        return ans;
        
    }
};
