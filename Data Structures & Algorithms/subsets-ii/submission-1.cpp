class Solution {
public:
    set<vector<int>> check;
    void subset(vector<int> nums, vector<vector<int>>& ans, vector<int>& comb, int i){
        if (i==nums.size()){
            if(check.find(comb)==check.end()){
                check.insert(comb);
                ans.push_back(comb);
            }
            return;
        }
        comb.push_back(nums[i]);
        subset(nums, ans, comb, i+1);
        comb.pop_back();
        subset(nums, ans, comb, i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> comb;
        subset(nums, ans, comb, 0);
        return ans;
    }
};
