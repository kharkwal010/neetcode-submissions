class Solution {
public:
    vector<vector<int>> memo;
    int score(vector<int>& nums, vector<int>& mul, int i, int j){
        if(j==mul.size()) return 0;
        if(memo[i][j]!=INT_MIN) return memo[i][j];
        int ans = INT_MIN;
        int l = nums.size() - (j - i) - 1;
        ans = max(ans, nums[i]*mul[j] + score(nums, mul, i+1, j+1));
        ans = max(ans, nums[l]*mul[j] + score(nums, mul, i, j+1));
        return memo[i][j] = ans;
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
       memo.resize(m, vector<int>(m, INT_MIN));
       return score(nums, multipliers, 0, 0);
    }
};