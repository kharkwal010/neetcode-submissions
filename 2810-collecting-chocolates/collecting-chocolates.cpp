class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        long long ans = LLONG_MAX;
        vector<int> cost(n, INT_MAX);
        for(int j=0; j<n; j++){
            for(int i=0; i<n; i++){
                int k = (i+j)%n;
                cost[k] = min(cost[k], nums[i]);
            }
            long long sum = (long long)j*x;
            for(long long c: cost) sum += c;
            ans = min(ans, sum);
        }
        
        return ans;

    }
};