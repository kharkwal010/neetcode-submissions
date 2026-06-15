class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int sum = nums[0];
        for(int i=1; i<nums.size(); i++){
            sum = nums[i]+sum;
            if(sum<0){
                sum =0;
                res = max(nums[i], res);
            }
            else res= max(res, sum);
        }
        return res;
    }
};
