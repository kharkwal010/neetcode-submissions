class Solution {
public:
    vector<vector<int>> memo;
    int swapping(vector<int>& nums1, vector<int>& nums2, int i, int pswap){
        if(i==nums1.size()) return 0;
        if(memo[i][pswap]!=-1) return memo[i][pswap];
        int ans = INT_MAX;
        if(!(i==0 || (nums1[i]>nums1[i-1] && nums2[i]>nums2[i-1]))){
           swap(nums1[i], nums2[i]);
           ans = min(ans, 1 + swapping(nums1, nums2, i+1, 1));
           swap(nums1[i], nums2[i]);
        }
        else if(!(i==0 || (nums1[i]>nums2[i-1] && nums2[i]>nums1[i-1]))){
            ans = min(ans, swapping(nums1, nums2, i+1, 0));
        }
        else{
            ans = min(ans, swapping(nums1, nums2, i+1, 0));
            swap(nums1[i], nums2[i]);
            ans = min(ans, 1 + swapping(nums1, nums2, i+1, 1));
            swap(nums1[i], nums2[i]);
        }
        return memo[i][pswap] = ans;


    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        memo.resize(nums1.size(), vector<int>(2, -1));
        return swapping(nums1, nums2, 0, 0);
    }
};