class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = 0;
        int ans = INT_MIN;
        int neg = 0;
        int nsum = 0;
        int osum = 0;
        for(int i=0; i<nums.size(); i++){
            osum = osum + nums[i];
            sum = sum + nums[i];
            nsum += nums[i];
            neg = min(neg, nsum);
            ans = max(ans, sum);
            if(sum<0) sum = 0;
            if(nsum>0) nsum = 0;
        }
        if(ans<0) return ans;
        return max(ans, osum-neg);
    }
};