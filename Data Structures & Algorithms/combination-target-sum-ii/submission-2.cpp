class Solution {
public:
    set<vector<int>> visited;
    void backtrack(vector<int> nums, int target, vector<int>& comb, vector<vector<int>>& ans, int i){
        if(i>nums.size() || target<0){
            return;
        }

        if(target == 0){
            if(visited.find(comb)==visited.end()){
                ans.push_back(comb);
                visited.insert(comb);
            }
            return;
        }
        comb.push_back(nums[i]);
         backtrack(nums, target - nums[i], comb, ans, i+1);
         comb.pop_back();
         backtrack(nums, target, comb, ans, i+1);       

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> comb;
        vector<vector<int>> ans;
        backtrack(candidates, target, comb, ans, 0);
        return ans;
        
    }
};
