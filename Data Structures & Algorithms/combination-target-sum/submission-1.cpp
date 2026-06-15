class Solution {
public:
    void comb(vector<int>& nums, int target, vector<int> ans, vector<vector<int>>& result, int index){
        if(target==0){
            result.push_back(ans);
            return;
        }
        else if(target<0){
            return;
        }
        for(int i=index; i<nums.size(); i++){
            ans.push_back(nums[i]);
            comb(nums, target-nums[i], ans, result, i);
            ans.pop_back();
        }
        return;
    }
  

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        comb(nums, target, {}, result, 0);
        return result;
    }
};
