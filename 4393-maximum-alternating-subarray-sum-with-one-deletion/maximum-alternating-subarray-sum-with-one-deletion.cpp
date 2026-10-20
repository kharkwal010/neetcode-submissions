class Solution {
public:
    vector<vector<vector<long long>>> memo;

    long long solve(vector<int>& nums, int i, bool add, bool skip){
        if(i==nums.size()) return 0;
        if(memo[i][add][skip]!=-1) return memo[i][add][skip]; 
        long long ans = 0;
        if(skip) ans = max(ans, solve(nums, i+1, add, !skip));
        long long term = (add) ? nums[i] : nums[i]*-1;
        ans = max(ans, term + solve(nums, i+1, !add, skip));
        return memo[i][add][skip]=ans;
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        memo.resize(n, vector<vector<long long>>(2, vector<long long>(2, -1)));
        long long ans = LLONG_MIN;
        for(int i=0; i<nums.size(); i++){
            ans = max(ans, nums[i] + solve(nums, i+1, false, true));
        }
        return ans;
    }
};