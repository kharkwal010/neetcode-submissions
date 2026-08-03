class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l<=r){
            if(nums[l]<nums[r]) return nums[l];
            else if(nums[l]==nums[r]) r--;
            else{
                int m = (l + r) / 2;
                if(nums[m]<=nums[r]) r = m;
                else l = m+1;
            }
        }
        return nums[l];
    }
};