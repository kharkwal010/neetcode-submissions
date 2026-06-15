class Solution {
public:
    void permutations(vector<int> nums, vector<vector<int>>& ans, int layer){
        if (layer==nums.size()-1){
            ans.push_back(nums);
            return;
        }
        for (int i=layer; i<nums.size(); i++){
            swap(nums[i], nums[layer]);
            permutations(nums, ans, layer+1);
            swap(nums[i], nums[layer]);

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permutations(nums, ans, 0);
        return ans;
    }
};
