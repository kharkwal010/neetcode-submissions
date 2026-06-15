class Solution {
public:
    unordered_map<int, int> memo;
    bool summing(vector<int> nums, int i, int sum, bool ans){
        if(sum==0){
            ans = true;
            return ans;
        }
        if(sum<0 || i==nums.size()-1){
            return ans;
        }
        if(memo.find(sum)!=memo.end()){
            return memo[sum];
        }
        bool a = summing(nums, i+1, sum - nums[i], ans);
        bool b = summing(nums, i+1 , sum, ans);
        memo[sum]=a||b;
        return a||b;
    }
   
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        if (sum%2==1){
            return false;
        }
        else sum = sum /2;
        bool ans = false;
        return summing(nums, 0, sum, ans);

        
    }
};
