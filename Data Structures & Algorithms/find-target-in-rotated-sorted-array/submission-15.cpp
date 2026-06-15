class Solution {
public:
    int find(vector<int>& nums, int target, int left, int right){
        if(nums[left]==target) return left;
        if(nums[right]==target) return right;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]> target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        if(nums[left]==target) return left;
        if(nums[right]==target) return right;
        if(nums.size()<=2){
            return -1;
        }
        int min_i;
        if(nums[right]<nums[right-1]) min_i = right;
        else if(nums[left]<nums[right]) min_i = left;
        else{
            while(left<=right){
                int mid = (left+right)/2;
                if(nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1]){
                    min_i = mid;
                    break;
                }
                else if(nums[mid]>nums[right]){
                    left = mid + 1;
                }
                else right = mid -1;
            }
        }
        if(target>nums[right]) return find(nums, target, 0, min_i-1);
        return find(nums, target, min_i, right);
    }
};
