class Solution {
public:
    vector<vector<int>> memo;
    int split(vector<int>& prefix, int i, int k){
        if(k==0) return prefix[prefix.size()-1] - prefix[i-1];
        if(memo[i][k]!=-1) return memo[i][k];
        int ans = INT_MAX;
        for(int j=i; j<prefix.size()-k; j++){
            ans = min(ans, max(prefix[j]-prefix[i-1], split(prefix, j+1, k-1)));
        }
        return memo[i][k]=ans;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n+1, 0);
        for(int i=1; i<prefix.size(); i++) prefix[i] = prefix[i-1] + nums[i-1];
        memo.resize(n+1, vector<int>(k, -1));
        return split(prefix, 1, k-1);
    }
};