class Solution {
public:
    vector<vector<int>> memo;
    int connect(vector<int>& nums1, vector<int>& nums2, int i, int j){
        if(i==nums1.size() || j==nums2.size()) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        int ans = 0;
        ans = max(ans, connect(nums1, nums2, i+1, j));
        ans = max(ans, connect(nums1, nums2, i, j+1));
        if(nums1[i]==nums2[j]) ans = max(ans, 1+connect(nums1, nums2, i+1, j+1));
        return memo[i][j] = ans;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        memo.resize(n, vector<int>(m, -1));
        return connect(nums1, nums2, 0, 0);
    }
};