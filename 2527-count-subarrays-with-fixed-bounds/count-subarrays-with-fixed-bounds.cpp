class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int ibad = -1;
        int imin = -1;
        int imax = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<minK || nums[i]>maxK) ibad = i;
            if(nums[i]==minK) imin = i;
            if(nums[i]==maxK) imax = i;
            ans += max(0, min(imin, imax) - ibad);
        }
        return ans;
    }
};