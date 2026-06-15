class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[nums.size()-1];
        int one= nums[nums.size()-1];
        int two;
        for (int i=nums.size()-2; i>=0; i--){
            two = max(nums[i]+one, nums[i]);
            if (res<two){
                res=two;
            }
            one = two;
        }
        return res;
    }
};
