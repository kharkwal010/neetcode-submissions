class Solution {
public:
    bool check(vector<int>& nums, int l, int r, int target){
        while(l<=r){
            int m = (l+r)/2;
            if(nums[m]==target) return true;
            else if(nums[m]>target) r = m-1;
            else l = m+1;
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        if(nums[l]==target || nums[r]==target) return true;
        while(l<r && nums[l]==nums[r]){
            l++;
        }
        if (nums[l]<nums[r]) return check(nums, l, r, target);
        int left = l;
        int right = r;
        while(left<right){
            int m = (left+right)/2;
            if(nums[m]<=nums[r]) right = m;
            else left = m+1;
        }
        if(nums[r]>target) return check(nums, left, r, target);
        return check(nums, l, left-1, target);
    }
};