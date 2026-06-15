class Solution {
public: 
    unordered_map<int, bool> memo;
    bool check(vector<int> nums, int sum, int target, int i){
        if(i>nums.size() || target<sum){
            return false;
        }
        if(sum==target){
            return true;
        }
        // if(memo.find(sum)!=memo.end()){
        //     return memo[sum];
        // }
        bool ans = check(nums, sum+nums[i], target, i+1) || check(nums, sum, target, i+1);

        // memo[sum]=main;        
        return ans;

    }
   
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i= 0; i<nums.size(); i++){
            sum= sum + nums[i];
        }   
        if (sum%2!=0){
            return false;
        }
        else{
            sum = sum/2;
        }
        return check(nums, 0, sum, 0);

    }
};
