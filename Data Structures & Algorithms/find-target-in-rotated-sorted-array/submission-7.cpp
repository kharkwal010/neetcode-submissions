class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        int extreme = nums.size()-1;
                
            while(right>=left){
                if (nums[left]==target){
                    return left;
                }
                if (nums[right]==target){
                    return right;
                }
                int mid = (left + right)/ 2;
                
                if (nums[mid]==target){
                    return mid;
                }
                if (nums[0]>target){
                    if (nums[mid]>target){
                        if (nums[0]>nums[mid]){
                            right=mid-1;
                        }
                        else{
                            left = mid+1;
                        }
                    }
                    else{
                        left =mid+1;
                    }
                }
                if (nums[0]<target){
                    if (nums[mid]<target){
                        if (nums[extreme]>nums[mid]){
                            right=mid-1;
                        }
                        else{
                            left = mid+1;
                        }
                    }
                    else{
                        right =mid - 1;
                    }
                }
            }
        return -1;
    }
};
