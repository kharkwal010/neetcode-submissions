class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0;
        long long gap = INT_MAX;
        int last = nums2[nums2.size()-1];
        for(int i=0; i<nums1.size(); i++){
            ans += abs(nums1[i] - nums2[i]);
            if((nums1[i]<=last && nums2[i]>=last) || (nums1[i]>=last && nums2[i]<=last))gap = 0;
            else{
                long long g = min(abs(nums1[i]-last), abs(nums2[i]-last));
                gap = min(gap, g);
            }
        }
        return gap + ans + 1;
    }
};