class Solution {
public:
    int search(vector<int>& nums, int target) {
        int right = nums.size()-1;
        int left = 0;
        while (right>=left){
            if (nums[right]==target){
                return right;
            }
            if (nums[left]==target){
                return left;
            }
            int mid = (right + left) / 2;
            if (mid == right || mid == left){
                return -1;
            }
            if (nums[mid]>target){
                right = mid;
            }
            else if (nums[mid]<target){
                left = mid;
            }
            if (nums[mid]==target){
                return mid;
            }
        }
        return -1;
    }
};
