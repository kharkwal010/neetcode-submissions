class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size()==0){
            return 0;
        }
       int maxi = nums[nums.size()-1];
       int mini = nums[nums.size()-1];
       int res = nums[nums.size()-1];
       for (int i = nums.size()-2; i>=0; i--){
        int temp = maxi;
        maxi = max(max(nums[i], nums[i]* maxi), nums[i]*mini);
        mini = min(min(nums[i], nums[i]*mini), nums[i]*temp);
        res = max(res, maxi);
       } 
       return res;
    }
};
