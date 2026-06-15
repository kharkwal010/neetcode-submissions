class Solution {
public:
    vector<vector<int>> memo;
    int coins(vector<int>& nums, int l, int r){
        if(l>r) return 0;
        if(memo[l][r]!=INT_MAX) return memo[l][r];
        int ans = 0;
        for(int i=l; i<=r; i++){
            ans= max(ans, coins(nums, l, i-1)+nums[l-1]*nums[i]*nums[r+1]+ coins(nums, i+1, r));
        }
        memo[l][r] = ans;
        return ans;
    }
    int maxCoins(vector<int>& nums) {
        memo.resize(nums.size()+2, vector<int>(nums.size()+2, INT_MAX));
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        return coins(nums, 1, nums.size()-2);
    }
};
