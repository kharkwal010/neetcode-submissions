class Solution {
public:
    vector<int> memo;
    int jumps(vector<int>& nums, int i, int& target){
        if(i==nums.size()-1) return 0;
        if(memo[i]!=-1) return memo[i];
        int ans = INT_MIN;
        for(int j=i+1; j<nums.size(); j++){
            if(abs(nums[i]-nums[j])<=target) ans = max(ans, 1 + jumps(nums, j, target));
        }
        return memo[i] = ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        memo.resize(n, -1);
        int ans = jumps(nums, 0, target);
        if(ans<0) return -1;
        return ans;
    }
};