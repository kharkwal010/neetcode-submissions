class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        for(int i=1; i<n; i++){
            if(nums[i]>=nums[i-1]) left[i] = 1 + left[i-1];
        }
        if(left[n-1]==nums.size()) return nums.size();
        for(int i=n-2; i>=0; i--){
            if(nums[i]<=nums[i+1]) right[i] = 1 + right[i+1];
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            int l = (i==0) ? 0 : left[i-1];
            int r = (i==n-1) ? 0 : right[i+1];
            if(i==0 || i==n-1 || nums[i-1]<=nums[i+1]) ans = max(ans, 1 + l + r);
            else ans = max(ans, max(l, r) + 1); 
        }
        return ans;
    }
};