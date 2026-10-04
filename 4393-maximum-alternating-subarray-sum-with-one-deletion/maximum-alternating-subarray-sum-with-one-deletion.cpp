class Solution {
public:
    vector<vector<vector<long long>>> memo;
    long long sum(vector<int>& nums, int i, bool del, bool add){
        if(i==nums.size()) return 0;
        if(memo[i][del][add]!=LLONG_MIN) return memo[i][del][add];
        long long ans = 0;
        int sign = (add) ? 1 : -1;
        long long pick = sign * nums[i] + sum(nums, i+1, del, !add);
        ans = max(ans, pick);
        if(del){
            long long skip = sum(nums, i+1, !del, add);
            ans = max(ans, skip);
        }
        return memo[i][del][add] = ans;
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        memo.resize(n, vector<vector<long long>>(2, vector<long long>(2, LLONG_MIN)));
        long long ans = LLONG_MIN;
        for(int i=0; i<nums.size(); i++){
            long long val = nums[i] + sum(nums, i+1, true, false);
            ans = max(ans, val);
        }
        return ans;
    }
};