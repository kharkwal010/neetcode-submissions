class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> dec(n, 1);
        vector<int> inc(n, 1);
        for(int i=n-2; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(nums[i]>nums[j]) dec[i] = max(dec[i], 1 + dec[j]);
            }
        }
        for(int i=1; i<nums.size(); i++){
            for(int j=i-1; j>=0; j--){
                if(nums[i]>nums[j]) inc[i] = max(inc[i], 1 + inc[j]);
            }
        }

        int ans = 0;
        for(int i=1; i<n-1; i++){
            if(inc[i]>1 && dec[i]>1) ans = max(ans, inc[i] + dec[i] - 1);
        }
        return n - ans;
        

    }
};