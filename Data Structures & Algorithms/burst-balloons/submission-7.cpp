class Solution {
public:
    vector<vector<int>> memo;
    int burst(vector<int>& nums, int l, int r){
        if(r-l==1) return 0;
        if(memo[l][r]!=INT_MAX) return memo[l][r];
        int ans = INT_MIN;
        for(int i=l+1; i<r; i++){
            ans = max(ans, burst(nums, l, i) + nums[l]*nums[i]*nums[r] + burst(nums, i, r));
        }
        memo[l][r] = ans;
        return ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        memo.resize(nums.size(), vector<int>(nums.size(), INT_MAX));
        return burst(nums, 0, nums.size()-1);

    }
};
