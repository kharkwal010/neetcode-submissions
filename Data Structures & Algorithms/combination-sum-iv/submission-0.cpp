class Solution {
public:
    unordered_map<int, int> memo;
    int sum(vector<int> nums, int target, int amount){
        if(amount==target){
            return 1;
        }
        if(amount>target){
            return 0;
        }
        if(memo.find(amount)!=memo.end()){
            return memo[amount];
        }
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            ans = ans + sum(nums, target, amount + nums[i]);
        }
        memo[amount]=ans;
        return memo[amount];
    }
    int combinationSum4(vector<int>& nums, int target) {
        return sum(nums, target, 0);
    }
};