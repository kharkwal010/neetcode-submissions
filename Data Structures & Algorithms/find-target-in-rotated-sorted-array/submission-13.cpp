class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size()-1;
        int left = 0;
        int right = nums.size()-1;
        if(nums[left]==target) return left;
        if(nums[right]==target) return right;

        while(right>=left){
            int mid = (left + right)/ 2;
            if  (nums[mid]==target){
                return mid;
            }
            if(nums[0]> target){
               if(nums[mid]>target){
                if(nums[mid]>nums[n]){
                    left = mid + 1;
                }
                else{
                    right = mid -1;
                }
               }
               else left = mid +1 ;     
            }
            else{
                if(nums[mid]>target){
                    right = mid - 1;
                }
                else{
                    if(nums[mid]>nums[n]){
                        left = mid +1;
                    }
                    else right = mid - 1;
                }
                
            }            
        }
        return -1;
    }
};
