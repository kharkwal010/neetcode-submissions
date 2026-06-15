class Solution {
public:
    int minimum(vector<int>& nums){
        int l = 0;
        int r = nums.size()-1;
        int right = r;
        if(nums[l]<nums[r]) return l;
        while(l<r){
            int m = (l+r)/2;
            if(nums[m]>nums[right]) l = m+1;
            else r = m;
        }
        return l;        
    }

    int find(vector<int>& nums, int target, int l, int r){
        while(l<=r){
            int m = (l+r)/2;
            if(nums[m]>target) r = m-1;
            else if(nums[m]<target) l = m+1;
            else return m;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        bool inc = true;
        if(nums[nums.size()-1]>=target) inc = false;
        int idx = minimum(nums);
        if(inc) return find(nums, target, 0, idx-1);
        return find(nums, target, idx, nums.size()-1);
    }
};
