class Solution {
public:
    vector<vector<vector<int>>> memo;
    int res(vector<int>& nums, int l, int r, bool one){
        if(l>r) return 0;
        if(memo[l][r][one]!=-1) return memo[l][r][one];
        int ans = (one) ? INT_MIN : INT_MAX;

        if(one){
            ans = max(ans, nums[l] + res(nums, l+1, r, !one));
            ans = max(ans, nums[r] + res(nums, l, r-1, !one));
        }
        else{
            ans = min(ans, res(nums, l+1, r, !one));
            ans = min(ans, res(nums, l, r-1, !one));
        }
        return memo[l][r][one] = ans;

    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n%2==0) return true;
        memo.resize(n, vector<vector<int>>(n, vector<int>(2, -1)));
        int sum = 0;
        for(int n: nums) sum+=n;
        int score = res(nums, 0, nums.size()-1, true);
        if(score>=(sum-score)) return true;
        return false;
        
    }
};