class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int mod = 1e9+7;
        int n = nums.size();
        vector<int> times(n, 0);
        for(auto ele: requests){
            times[ele[0]] += 1;
            if(ele[1]+1<n) times[ele[1]+1] -=1;
        }
        int prev = 0;
        for(int i=0; i<n; i++){
            times[i]+=prev;
            prev = times[i];
        }
        sort(times.rbegin(), times.rend());
        sort(nums.rbegin(), nums.rend());
        long long ans = 0;
        for(int i=0; i<n; i++){
            ans = (ans + (long long)times[i] * nums[i])%mod;
        }
        return ans;

    }
};