class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        if(r==0) return nums[0];
        while(l<=r){
            int m = (l + r) / 2;
            if(m>0 && nums[m]==nums[m-1]){
                if((m-l+1)%2==1) r = m-2;
                else l = m+1;
            }
            else if(m<nums.size()-1 && nums[m]==nums[m+1]){
                if((m-l+1)%2==0) r = m-1;
                else l = m+2;
            }
            else return nums[m];
        }
        return -1;
    }
};