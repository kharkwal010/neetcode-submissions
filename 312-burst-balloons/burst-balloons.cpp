class Solution {
public:
    vector<vector<int>> memo;
    int coins(vector<int>& nums, int l, int r){
        if(l>r) return 0;
        if(memo[l][r]!=-1) return memo[l][r];
        int ans = 0;
        for(int i=l; i<=r; i++){
            ans = max(ans, nums[l-1]*nums[i]*nums[r+1] + coins(nums, l, i-1) + coins(nums, i+1, r));
        }
        return memo[l][r] = ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        memo.resize(n, vector<int>(n, -1));
        return coins(nums, 1, nums.size()-2);
        
    }
};