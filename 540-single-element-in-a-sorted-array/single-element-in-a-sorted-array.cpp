class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        while(l<r){
            int m = l + (r - l)/2;
            bool left = false;
            if(nums[m]==nums[m-1]) left = true;
            else if(nums[m]!=nums[m+1]) return nums[m];
            if(m%2==1){
                if(left) l = m+1;
                else r = m-1;
            }
            else{
                if(left) r = m;
                else l = m;
            }
        }
        return nums[l];
    }
};