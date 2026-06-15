class Solution {
public:
    int findMin(vector<int> &nums) {
        int right=nums.size()-1;
        int left =0;
        if(nums[left]<=nums[right]){
            return nums[left];
        }
        if(nums[right]<nums[right-1]){
            return nums[right];
        }
        while(right>=left){
            int mid = (right + left) / 2;
            if(nums[mid]<nums[mid+1] && nums[mid]<nums[mid-1]){
                return nums[mid];
            }
            else if(nums[mid]<nums[right]){
                right = mid - 1;
            }
            else left = mid + 1;
        }
    }
};
