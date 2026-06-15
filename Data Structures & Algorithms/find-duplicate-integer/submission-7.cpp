class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int num: nums){
            nums[abs(num)-1] = -1* nums[abs(num)-1];
            if(nums[abs(num)-1]>0){
                return abs(num);
            }
        }
       return -1; 
    }
};
