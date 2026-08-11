class Solution {
public:
    vector<int> memo;
    bool check(vector<int>& nums, int i){
        if(i==nums.size()) return true;
        if(memo[i]!=2) return memo[i];
        bool ans = false;
        if(i+1<nums.size() && nums[i]==nums[i+1]){
            ans = ans || check(nums, i+2);
            if(i+2<nums.size() && nums[i+2]==nums[i]) ans = ans || check(nums, i+3);
        }
        if(i+2<nums.size() && nums[i]==nums[i+1] -1 && nums[i] == nums[i+2] - 2){
            ans = ans || check(nums, i+3);
        }
        return memo[i] = ans;        
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        memo.resize(n, 2);
        return check(nums, 0);
    }
};