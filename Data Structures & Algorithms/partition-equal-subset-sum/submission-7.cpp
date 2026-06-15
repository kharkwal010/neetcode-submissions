class Solution {
public: 
    unordered_map<int, bool> memo;
    bool check(vector<int> nums, int sum, int i, bool ans){
        if(sum==0){
            ans = true;
            return ans;
        }
        if(i==nums.size()-1 || sum<0){
            return ans;
        }
        if(memo.find(sum)!=memo.end()){
            return memo[sum];
        }
        bool res = check(nums, sum-nums[i], i+1, ans) || check(nums, sum, i+1, ans);
        memo[sum]=res;
        return res;

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
        return check(nums, sum, 0, false);

    }
};
