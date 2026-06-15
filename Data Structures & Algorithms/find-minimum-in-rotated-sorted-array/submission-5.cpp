class Solution {
public:
    int findMin(vector<int> &nums) {
        int right=nums.size()-1;
        int left =0;
        if (nums[right]>= nums[left]){
            return nums[left];
        }
        
        while(right>=left){
            int mid = (right + left) / 2;
            if (nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1]){
                return nums[mid];
            }
            if(nums[mid+1]==nums[nums.size()-1]){
                return nums[nums.size()-1];
            }
            if (nums[mid]>nums[right]){
                left = mid;
            }
            else {
                right = mid;
            }
            
        }

    }
};
