class Solution {
public:
    vector<vector<int>> memo;
    int score(vector<int>& nums, vector<int>& mul, int k, int i, int& n){
        if(k==mul.size()) return 0;
        if(memo[i][k]!=INT_MIN) return memo[i][k];
        int ans = INT_MIN;
        int j = n - (k-i) - 1;
        ans = max(ans, mul[k]*nums[i] + score(nums, mul, k+1, i+1, n));
        ans = max(ans, mul[k]*nums[j] + score(nums, mul, k+1, i, n));
        return memo[i][k] = ans;
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        int n = nums.size();
        memo.assign(m, vector<int>(m, INT_MIN));
        return score(nums, multipliers, 0, 0, n);
    }
};