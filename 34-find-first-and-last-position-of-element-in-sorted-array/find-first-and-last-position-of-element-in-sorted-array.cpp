class Solution {
public:
    int right(vector<int>& nums, int target, int l, int r){
        while(l<=r){
            int m = (l + (r - l)/ 2);
            if(nums[m]==target){
                if(m+1>=nums.size() || nums[m+1]!=target) return m;
                else l = m+1;
            }
            else if(nums[m]<target) l = m+1;
            else r = m-1;
        }
        return -1;
    }
    int left(vector<int>& nums, int target, int l, int r){
        while(l<=r){
            int m = (l + (r - l)/ 2);
            if(nums[m]==target){
                if(m-1<0 || nums[m-1]!=target) return m;
                else r = m-1;
            }
            else if(nums[m]>target) r = m-1;
            else l = m+1;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int r = right(nums, target, 0, nums.size()-1);
        if(r==-1) return {-1, -1};
        int l = left(nums, target, 0, nums.size()-1);
        return {l, r};
    }
};