class Solution {
public:
    void backtrack(vector<int> nums, vector<vector<int>>& ans, vector<int>& element, int i){
        if(i==nums.size()){
            ans.push_back(element);
            return;
        }
        //pick
        element.push_back(nums[i]);
        backtrack(nums, ans, element, i+1);
        // dont pick
        element.pop_back();
        backtrack(nums, ans, element, i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> element;
        backtrack(nums, ans, element,0);
        return ans;
    }
};
