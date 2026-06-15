class Solution {
public: 
    vector<vector<int>> memo;
    bool check(vector<int>& nums, int sum, int i){
        if(sum==0) return true;
        if(i==nums.size() || sum<0) return false;
        if(memo[i][sum]!=-1) return memo[i][sum];
        memo[i][sum] = check(nums, sum, i+1) || check(nums, sum-nums[i], i+1);
        return memo[i][sum];

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
        memo.resize(nums.size(), vector<int>(sum+1, -1));
        return check(nums, sum, 0);

    }
};
