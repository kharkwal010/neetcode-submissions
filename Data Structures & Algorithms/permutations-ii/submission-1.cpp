class Solution {
public:
    set<vector<int>> visited;
    void perm(vector<int> nums, int i, vector<vector<int>>& ans){
        if(i==nums.size()){
            if(!visited.count(nums)){
                ans.push_back(nums);
                visited.insert(nums);
            }
        }
        for(int j=i; j<nums.size(); j++){
            swap(nums[i], nums[j]);
            perm(nums, i+1, ans);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        perm(nums, 0, ans);
        return ans;
    }
};