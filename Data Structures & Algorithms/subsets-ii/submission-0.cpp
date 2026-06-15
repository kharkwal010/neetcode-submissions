class Solution {
public:
    set<vector<int>> check;
    void subset(vector<int> nums, vector<vector<int>>& ans, vector<int>& comb, int i){
        if (i==nums.size()){
            vector<int> temp = comb;
            sort(temp.begin(), temp.end());
            if(check.find(temp)==check.end()){
                check.insert(temp);
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
        vector<vector<int>> ans;
        vector<int> comb;
        subset(nums, ans, comb, 0);
        return ans;
    }
};
