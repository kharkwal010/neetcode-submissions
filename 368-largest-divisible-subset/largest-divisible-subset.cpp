class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& nums, int prev, int i){
        if(i==nums.size()) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];
        int previous = (prev==nums.size()) ? 1 : nums[prev];
        int ans = 0;
        if(nums[i]%previous==0) ans = max(ans, 1 + solve(nums, i, i+1));
        ans = max(ans, solve(nums, prev, i+1));
        return dp[i][prev] = ans;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        dp.resize(n, vector<int>(n+1, -1));
        solve(nums, n, 0);
        vector<int> ans;
        int prev = n;
        int maxi = dp[0][n];
        // cout<<maxi<<endl;
        for(int i=0; i<nums.size(); i++){
            int previous = (prev==nums.size()) ? 1 : nums[prev];
            if(nums[i]%previous==0 && solve(nums, i, i+1)==maxi-1){
                ans.push_back(nums[i]);
                prev = i;
                maxi--;
                if(maxi==0) break;
            }
        }  
        return ans;      

    }
};