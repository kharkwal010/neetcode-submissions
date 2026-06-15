class Solution {
public:
     //task is to incorporate dp;
    vector<vector<int>> memo;
    int total;
    int possible(vector<int> nums,int i, int sum, int target){
       if (i==nums.size()){
        if (sum==target){
            return 1;
        }
        else return 0;
       }
        if(memo[i][total+sum]!=INT_MIN){
            return memo[i][total+sum];
        }
       memo[i][total+sum] = possible(nums, i+1, sum + nums[i], target) + possible(nums, i+1, sum - nums[i], target);
        return memo[i][total+sum];
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        total = accumulate(nums.begin(), nums.end(), 0);
        memo = vector<vector<int>>(nums.size(), vector<int>(2*total+1, INT_MIN));
        return possible(nums, 0, 0, target);
        

    }
};
