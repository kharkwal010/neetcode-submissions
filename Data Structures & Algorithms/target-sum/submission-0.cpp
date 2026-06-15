class Solution {
public:
     
    int possible(vector<int> nums,int i, int sum, int target){
     
       if (i==nums.size()){
        if (sum==target){
            return 1;
        }
        else return 0;
       }
       return possible(nums, i+1, sum + nums[i], target) + possible(nums, i+1, sum - nums[i], target);
        
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return possible(nums, 0, 0, target);
        

    }
};
